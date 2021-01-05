C program that runs a plurality election

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcasecmp(name, candidates[j].name)  == 0) //Checks if name entered matches a candidate's name (ignoring case)
        {
            candidates[j].votes += 1; //Adds a vote to the candidate's total if entered name matches
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int k, most_votes = 0;
    //Scans through all candidates' votes and stores the candidate(s) with the most vote (Reversed selection sort)
    for (k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes > most_votes) 
        {
            most_votes = candidates[k].votes;
        }
    }
    
    //Checks each candidates' votes and stores the candidate(s) whose vote equals to the most votes
    for (k = 0; k < candidate_count; k++) 
    {
        if (candidates[k].votes == most_votes)
        {
            printf("%s\n", candidates[k].name); //Prints name of candidate(s) with most votes
        }
    }
    return;
}
