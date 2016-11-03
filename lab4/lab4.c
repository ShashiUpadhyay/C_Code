
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* Part A: Time Difference - STARTS */

/* Structure to input the time */
struct time{
    int hours;
    int minutes;
    int seconds;
};

/* function to convert the time in seconds */
int numSeconds(int hours, int minutes, int seconds){
    int conversion_seconds;
    conversion_seconds = hours*60*60 + minutes*60 + seconds;
    return conversion_seconds;
}

/* function to convert the time in 24 hour format */
struct time conversion_24_hour_format(int seconds){
    struct time time_difference_conversion;
    int rem_scds;
    time_difference_conversion.hours = seconds/3600;
    rem_scds = seconds%3600;
    time_difference_conversion.minutes = rem_scds/60;
    time_difference_conversion.seconds = rem_scds%60;
    return time_difference_conversion;
}

/* function to print the difference in two times */
struct time time_difference(struct time time1, struct time time2){
    struct time difference_in_time;
    int difference_seconds;
    
    difference_seconds =
            numSeconds(time2.hours, time2.minutes, time2.seconds) -
            numSeconds(time1.hours, time1.minutes, time1.seconds);
    
    difference_in_time = conversion_24_hour_format(difference_seconds);
    
    return difference_in_time;
}

/* function to print the time in HH:MM:SS format */
void print_time(struct time input1, struct time input2){
        struct time difference;
        difference = time_difference(input1,input2);
        printf("Difference between %02d:%02d:%02d ", input1.hours, input1.minutes, input1.seconds);
        printf("and %02d:%02d:%02d ", input2.hours, input2.minutes, input2.seconds);
        printf(" = %02d:%02d:%02d \n", difference.hours, difference.minutes, difference.seconds);
}
/* Part A: Time Difference - ENDS */


/* Part B: Time Difference - STARTS */
enum Months{
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
};

char *month_array[12] = {
    "JANUARY",
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER"
};

struct dateTime{
    enum Months month;
    int day;
    int year;
    /* Using the time struct */
    struct time struct1;
};

/* function to print the date and time */
void print_date_time(struct dateTime input_dttime){
    printf("%s %02d %04d %02d:%02d \n",
           month_array[input_dttime.month],
           input_dttime.day, input_dttime.year,
           input_dttime.struct1.hours,
           input_dttime.struct1.minutes);
}

/* Part B: Time Difference - ENDS */


/* --------------     Part 2 -- Tournament STARTS -------------   */
struct Team{
    char *team_name;
    int scores;
    int handicap;
};


/* Function to generate ramdom number */
int random_number_generator(int range){
    range = rand() %range + 1;
    return range;
}

/* Function to decide winner between two opponents */
struct Team* game(struct Team* team1, struct Team* team2){
    printf(" %s v/s %s", team1->team_name, team2->team_name);
    team1->scores = random_number_generator(80);
    team2->scores = random_number_generator(80);
    //    printf("Contender 1 : %s and Contender 2 : %s\n",team1->team_name,team2->team_name);
    //    printf("Score - Team 1 = %d and Team 2 = %d\n",team1->scores,team2->scores);
    
    team1->handicap = random_number_generator(20);
    team2->handicap = random_number_generator(20);
    //    printf("Handicap Contribution - Team 1 = %d and Team 2 = %d\n",team1->handicap,team2->handicap);
    team1->scores+=team1->handicap;
    team2->scores+=team2->handicap;
    
    //    printf("Total Score - Team 1 = %d and Team 2 = %d\n",team1->scores,team2->scores);
    if(team1->scores > team2->scores){
         printf(" \t%s\n",team1->team_name);
        return team1;
    }else{
        printf(" \t%s\n",team2->team_name);
        return team2;
    }
}

/* Function for the tournament */
struct Team* tournament(struct Team* league[8]){
    struct Team *contender1;
    struct Team *contender2;
    struct Team *winner;
    char* round2[4];
    char* round3[2];
    
    winner = (struct Team*)malloc(sizeof(struct Team));
    contender1 = (struct Team*)malloc(sizeof(struct Team));
    contender2 = (struct Team*)malloc(sizeof(struct Team));
    
    int i,j,game_count;
    j=0;
    game_count=0;
    
    srand(time(0));
    
    printf("Round 1 \n");
    
    printf("Game\tParticipants\tWinner \n");
    for(i=0;i<4;i++){
        printf(" %d\t",++game_count);
        contender1->team_name = league[j]->team_name;
        contender2->team_name = league[++j]->team_name;
        winner = game(contender1,contender2);
        round2[i]=winner->team_name;
        j++;
    }
    
    printf("\nRound 2\n");
    printf("Game\tParticipants\tWinner \n");
    j=0,game_count=0;
    for(i=0;i<2;i++){
        printf(" %d\t",++game_count);
        contender1->team_name = round2[j];
        contender2->team_name = round2[++j];
        winner = game(contender1,contender2);
        round3[i]=winner->team_name;
        j++;
    }
    
    printf("\nRound 3\n");
    printf("Game\tParticipants\tWinner \n");
    printf("Finale\t");
    contender1->team_name = round3[0];
    contender2->team_name = round3[1];
    winner = game(contender1,contender2);
    
    return winner;
}

/* --------------     Part 2 -- Tournament ENDS -------------   */

int main(){
    
    /* Part A: Time Difference - STARTS */
    struct time time_input[10] = {
                            {3,45,15},
                            {9,44,03},
                            {1,30,45},
                            {16,30,45},
                            {1,23,01},
                            {12,11,12},
                            {00,01,01},
                            {23,59,59},
                            {12,00,00},
                            {12,00,00}
    };
    
    print_time(time_input[0], time_input[1]);
    print_time(time_input[2], time_input[3]);
    print_time(time_input[4], time_input[5]);
    print_time(time_input[6], time_input[7]);
    print_time(time_input[8], time_input[9]);
   /* Part A: Time Difference - ENDS */
    
   /* Part B: Time Difference - STARTS */
    struct dateTime datetime[3] = {
        {JANUARY,19,1809,{12,01,00}},
        {NOVEMBER,11,1922,{6,00,00}},
        {JANUARY,6,2000,{8,22,00}}
    };
    printf("\n");
    print_date_time(datetime[0]);
    print_date_time(datetime[1]);
    print_date_time(datetime[2]);
   /* Part B: Time Difference - ENDS */
    
    /* Part 2 -- Tournament (Extra Credit) - START */
    printf("\nTournament\n");
    
    struct Team AA = {"AA"};
    struct Team BB = {"BB"};
    struct Team CC = {"CC"};
    struct Team DD = {"DD"};
    struct Team EE = {"EE"};
    struct Team FF = {"FF"};
    struct Team GG = {"GG"};
    struct Team HH = {"HH"};
    
    struct Team* league [8] = {&AA, &BB, &CC, &DD, &EE, &FF, &GG, &HH};
    
    struct Team *winner;
    winner=tournament(league);
    printf("\nChampion\tScore\n");
    printf("%8s\t", winner->team_name);
    printf("%2d\n", winner->scores);
    /* Part 2 -- Tournament (Extra Credit) - END */
    
    return 0;

}


