#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

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
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count;)
    {
        int result = strcmp(name, candidates[i]);

        if (result == 0)
        {
            ranks[rank] = i;
            if (rank > 0)
            {
                for (int z = 0; z < rank; z++)
                {
                    if (ranks[rank] == ranks[z])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        i++;
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int preferred = candidate_count;
    for (int i = 0; i < preferred; i++)
    {
        for (int j = i + 1; j < preferred; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            printf("preferences[%i][%i] = %i\n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
        }

    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                printf("preferences[%i][%i] > preferences[%i][%i] = %s > %s\n", i, j, j, i, candidates[pairs[pair_count].winner], candidates[pairs[pair_count].loser]);
                pair_count++;
                printf("Pair count is = %i\n", pair_count);
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                printf("preferences[%i][%i] < preferences[%i][%i] = %s < %s\n", i, j, j, i, candidates[pairs[pair_count].loser], candidates[pairs[pair_count].winner]);
                pair_count++;
                printf("Pair count is = %i\n", pair_count);
            }
            else
            {
                printf("preferences[%i][%i] == preferences[%i][%i] = %i == %i\n", i, j, j, i, preferences[i][j], preferences[j][i]);
                printf("Pair count is = %i\n", pair_count);
            }
        }

    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i Winner - %s | Loser - %s ", i + 1, candidates[pairs[i].winner], candidates[pairs[i].loser]);
        printf("with a score %i | %i\n", preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);

    }
    int sorted[pair_count];
    int winner_rank[pair_count];
    int highest = 0;
    for (int i = 0; i < pair_count; i++)
    {
        winner_rank[i] = preferences[pairs[i].winner][pairs[i].loser];
    }
    for (int z = 0; z < pair_count; z++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (highest < winner_rank[j])
            {
                highest =  winner_rank[j];
            }
        }
        for (int i = 0; i < pair_count; i++)
        {

            if (highest == winner_rank[i])
            {
                sorted[z] = i;
                winner_rank[i] = 0;
                highest = 0;
                printf("sorted[%i] = Pair %i\n", z, i + 1);
                break;
            }
        }
    }
    pair temp[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        temp[i] = pairs[i];
    }
    for (int i = 0; i < pair_count; i++)
    {
        pairs[i] = temp[sorted[i]];
    }

    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i Winner - %s | Loser - %s ", i + 1, candidates[pairs[i].winner], candidates[pairs[i].loser]);
        printf("with a score %i | %i\n", preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);

    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                locked[i][j] = false;
                break;
            }
        }
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].loser][pairs[i].winner] = false;
        if (i == candidate_count - (candidate_count - i))
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (locked[pairs[i].loser][j] == true)
                {
                    locked[pairs[i].winner][pairs[i].loser] = false;
                }
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for ( int j = 0; j < candidate_count; j++)
        {
            printf("locked[%i][%i] = %s\n", i, j, locked[i][j] ? "true" : "false");
        }
    }

    // locked[i][j] means i is locked in over j
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int false_count;

    for (int i = 0; i < candidate_count; i++)
    {
        false_count = 0;
        for (int k = 0; k < candidate_count; k++)
        {
            if (locked[k][i] == false)
            {
                false_count++;
            }
        }

        // Prints all the names that are the source of the graph
        if (false_count == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
}


