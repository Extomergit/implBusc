#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_time.h"


void prt_time (Time *time){
	
    char str[TIME_LEN];
	
    time_string(time, str);
	
    printf("%s", str);
	
}

Time *malloc_time() {
	
    Time *time = (Time *) malloc(sizeof(Time));
	
    return time;
}

Time *create_time(int hour, int minutes, int seconds) {
	
    Time *time = malloc_time();
	
    time->hour = hour;
	
    time->minute = minutes;
	
    time->second = seconds;
	
    return time;
}

int time_cmp(Time* time1, Time* time2){
	
    int time1_in_seconds = time_seconds(time1);
	
    int time2_in_seconds = time_seconds(time2);

    if (time1_in_seconds > time2_in_seconds){
		
        return 1;
		
    }
	else if(time1_in_seconds < time2_in_seconds){
		
        return -1;
		
    }
	else{
		
        return 0;
		
    }
}

int low(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) < 0;
}

int equal(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) == 0;
}

int high(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) > 0;
}

void time_string(Time* time, char *dest){
    char buffer[TIME_LEN] = {};
    snprintf(buffer, TIME_LEN, "%02d:%02d:%02d", time->hour, time->minute, time->second);
    strncpy(dest, buffer, TIME_LEN);
}

int time_seconds(Time *time){
    return 3600 * time->hour + 60 * time->minute + time->second;
}

void cpy_time(Time *from, Time *to)
{
    to->hour = from->hour;
    to->minute = from->minute;
    to->second = from->second;
}
