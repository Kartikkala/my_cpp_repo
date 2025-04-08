#include <stdio.h>

#define MAX_CANDIDATES 5

void add_candidate(int *votes, int size, int max_votes){
    static int id = 0;
    if(id >= MAX_CANDIDATES)
    {
        printf("Max number of candidates added!\n");
        return;
    }
        
    votes[id] = max_votes;
    printf("Candidate id %d added with %d votes.\n", id, votes[id]);
    id++;
    return;
}


int find_max(int *votes, int size)
{
    int max = -1;
    int id = 0;
    for(int i=0;i<size;i++)
    {
        if(votes[i] > max)
        {
            max = votes[i];
            id = i;
        }
    }
    return id;
}

int find_total(int *votes, int size)
{
    int total = 0;
    for(int i=0;i<size;i++)
    {
        total+= votes[i];
    }
    return total;
}

int percentage(int *votes, int size, int candidate_id)
{
    if(candidate_id >= MAX_CANDIDATES || candidate_id < 0)
    {
        printf("Invalid candidate id.\n");
        return -1;
    }
    return (votes[candidate_id]/find_total(votes, size)) * 100;
}

int main(void)
{
    int votes[5] = {0};

    add_candidate(votes, 5, 8);
    add_candidate(votes, 5, 2);
    add_candidate(votes, 5, 4);
    add_candidate(votes, 5, 6);
    add_candidate(votes, 5, 9);

    int id = find_max(votes, 5);

    printf("Candidate id %d has max number of votes i.e.: %d", id, votes[id]);

}