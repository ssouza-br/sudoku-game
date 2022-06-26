void sort_pairs(void)
{
    int max_strength = 0;
    pair temp = {0, 0};

    for (int k = 0; k < pair_count - 1; k++)
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
