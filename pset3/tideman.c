#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// help variable source
typedef struct
{
    int sai;
    int recebe;
}
status;
status status_general[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_source(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
//     printf("status recebe A: %i status sai A: %i status recebe B: %i status sai B: %i status recebe C: %i status sai C: %i\n",
// status_general[0].recebe, status_general[0].sai, status_general[1].recebe, status_general[1].sai, status_general[2].recebe, status_general[2].sai);
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            printf("i: %i j: %i locked[i][j] %i\n", i, j, locked[i][j]);
        }
    }
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            //printf("%i %s\n", rank, name);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int j = 1; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count - j; i++)
        {
            preferences[ranks[i]][ranks[i + j]] = preferences[ranks[i]][ranks[i + j]] + 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
                k++;
            }
        }
    }
    pair_count = k;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int max_strength = 0;
    pair temp = {0, 0};

    for (int k = 0; k < pair_count - 1;k++)
    {
        for (int i = k; i < pair_count; i++)
        {
            //lista completa
            printf("par number: %i winner: %i loser: %i\n", i, pairs[i].winner, pairs[i].loser);
            int strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            printf("strengt: %i\n", strength);
            if (strength > max_strength)
            {
                max_strength = strength;
                temp.winner = pairs[k].winner;
                temp.loser =  pairs[k].loser;

                pairs[k].winner = pairs[i].winner;
                pairs[k].loser = pairs[i].loser;

                pairs[i].winner = temp.winner;
                pairs[i].loser = temp.loser;
            }
        }
        max_strength = 0;
    }
   }

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int temp_sai, temp_recebe;
        printf("par number: %i winner: %i loser: %i\n", i, pairs[i].winner, pairs[i].loser);
        temp_sai = status_general[pairs[i].winner].sai;
        temp_recebe = status_general[pairs[i].loser].recebe;
        printf("temp_sai: %i temp_recebe: %i\n", temp_sai, temp_recebe);
        status_general[pairs[i].winner].sai = 1;
        status_general[pairs[i].loser].recebe = 1;
        //printf("TRUE OR FALSE: %i\n", check_source());
        if (check_source())
        {
            printf("entrei\n");
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        else
        {
            status_general[pairs[i].winner].sai = temp_sai;
            status_general[pairs[i].loser].recebe = temp_recebe;
            printf("i: %i st_sai: %i st_recebe: %i\n", i, status_general[pairs[i].winner].sai, status_general[pairs[i].loser].recebe);
        }
    }
    return;
}

bool check_source(void)
{
    int k = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        printf("j: %i recebe: %i sai: %i\n", j, status_general[j].recebe, status_general[j].sai);
        if (status_general[j].recebe == 1 && status_general[j].sai == 1)
        {
            k++;
        }
    }
    if (k == candidate_count)
    {
        printf("k FALSE: %i\n", k);
        return false;
    }
    else
    {
        printf("k TRUE: %i\n", k);
        return true;
    }
}

bool column_free(int column_number)
{
    for (int j = 0; j < candidate_count; j++)
    {
        //verificar toda coluna se tudo está false, caso positivo tst1 = true
        if (locked[j][column_number] == true)
        {
            return false;
        }
    }
    return true;
}

bool line_true(int line_number)
{
    for (int j = 0; j < candidate_count; j++)
    {
        //verificar toda coluna se tudo está false, caso positivo tst1 = true
        if (locked[line_number][j] == true)
        {
            return true;
        }
    }
    return false;
}


// Print the winner of the election
void print_winner(void)
{
    typedef struct
    {
        int col_lock;
        int lin_lock;
    }
    tst;

    tst tst_list[candidate_count];
    int k = 0;
    bool tst1;
    bool tst2;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (tst1 && tst2)
            {
                printf("%s\n", candidates[i]);
                return;
            }
        }
    }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     if (tst_list[i].lin_lock == 1 && tst_list[i].col_lock == 0)
    //     {
    //         //printf("entrei no i: %i", i);
    //         printf("%s\n", candidates[i]);
    //         return;
    //     }
    // }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     if (status_general[i].recebe == 0 && status_general[i].sai == 1)
    //     {
    //         //printf("entrei no i: %i", i);
    //         printf("%s\n", candidates[i]);
    //         return;
    //     }
    // }

}