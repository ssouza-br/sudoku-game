#include <stdio.h>

int main(void)
{

}

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