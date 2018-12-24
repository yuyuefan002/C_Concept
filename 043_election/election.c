#include "election.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
//include any other headers you need here...

const char * parseName(const char * cur, state_t * stateInfo) {
  int i = 0;
  while (*cur != ':') {
    //only rejects '\n','\0',':'
    if (*cur == '\n' || *cur == '\0') {
      fprintf(stderr, "wrong data format for name\n");
      exit(EXIT_FAILURE);
    }
    //if the name is too long, it is a error
    //leave a place for '\0'
    if (i >= MAX_STATE_NAME_LENGTH - 1) {
      fprintf(stderr, "Usage: the state's name is too long\n");
      exit(EXIT_FAILURE);
    }
    stateInfo->name[i++] = *(cur++);
  }  //end while
  stateInfo->name[i] = '\0';
  cur++;
  return cur;
}

const char * parsePop(const char * cur, state_t * stateInfo) {
  while (*cur != ':') {
    //only accept digit
    if (isdigit(*cur)) {
      stateInfo->population = stateInfo->population * 10 + *cur - '0';
    }
    else {
      fprintf(stderr, "wrong data format in population\n");
      exit(EXIT_FAILURE);
    }
    cur++;
  }  //end while
  cur++;
  return cur;
}

const char * parseVote(const char * cur, state_t * stateInfo) {
  if (*cur == '\0') {
    fprintf(stderr, "there is no number for vote\n");
    exit(EXIT_FAILURE);
  }
  while (*cur != '\0') {
    //only accept digit
    if (isdigit(*cur)) {
      stateInfo->electoralVotes = stateInfo->electoralVotes * 10 + *cur - '0';
    }
    else {
      fprintf(stderr, "wrong data format for votes\n");
      exit(EXIT_FAILURE);
    }
    cur++;
  }  //end while
  return cur;
}

state_t parseLine(const char * line) {
  //STEP 1: write me
  if (line == NULL) {
    fprintf(stderr, "Usage: input a line for parse\n");
    exit(EXIT_FAILURE);
  }
  //initialize all variables, or will be wrong
  state_t stateInfo;
  stateInfo.name[0] = '\0';
  stateInfo.electoralVotes = 0;
  stateInfo.population = 0;
  const char * cur = line;
  //const char* parse*(const char* cur, state_t* s)
  //Parameter: pointer cur pointing to the information we need to parse
  //           parsed information will be stored in s
  //return the pointer pointing to the next information
  cur = parseName(cur, &stateInfo);
  cur = parsePop(cur, &stateInfo);
  cur = parseVote(cur, &stateInfo);
  return stateInfo;
}

unsigned int countElectoralVotes(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 2: write me
  unsigned int res = 0;
  for (size_t i = 0; i < nStates; i++) {
    //if(voteCounts[i]>stateData[i].population/2)
    //they are all int,using multiply is better than division
    if (2 * voteCounts[i] > stateData[i].population) {
      res += stateData[i].electoralVotes;
    }
  }  //end for
  return res;
}

void printRecounts(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 3: write me
  for (size_t i = 0; i < nStates; i++) {
    //implicity change int to double by mutiplying 100.0 at first
    //perc is the abbreviation of percentage
    double perc = 100.0 * voteCounts[i] / stateData[i].population;
    if (perc <= 50.5 && perc >= 49.5) {
      printf(
          "%s requires a recount (Candidate A has %.2f%% of the vote)\n", stateData[i].name, perc);
    }
  }  //end for
}

void printLargestWin(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 4: write me
  double largestNum = 0;    //storing the largest percentage of votes
  size_t largestState = 0;  //storing the state number which has largest percentage of votes
  for (size_t i = 0; i < nStates; i++) {
    double perc = 100.0 * voteCounts[i] / stateData[i].population;
    if (perc > largestNum) {
      largestNum = perc;
      largestState = i;
    }
  }  //end for
  printf("Candidate A won %s with %.2f%% of the vote\n", stateData[largestState].name, largestNum);
}
