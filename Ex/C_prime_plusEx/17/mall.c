# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "queue.c"
# define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);
void cyc(Queue * pq, int n);
void showrlt(Queue * pq, int n);

Queue line1, line2;
Item tmp;
int hours;
int perhour;
long cycle, cyclelimit;
long turnaways1 = 0;
long turnaways2 = 0;
long customers1 = 0;
long customers2 = 0;
long served1 = 0;
long served2 =0;
long sum_line1 = 0;
long sum_line2 = 0;
int wait_time1 = 0;
int wait_time2 = 0;
double min_per_cust;
long line_wait1 = 0;
long line_wait2 = 0;
long * turnaways[2] = {&turnaways1, &turnaways2};
long * customers[2] = {&customers1, &customers2};
long * served[2] = {&served1, &served2};
long * sum_line[2] = {&sum_line1, &sum_line2};
int * wait_time[2] = {&wait_time1, &wait_time2};
long * line_wait[2] = {&line_wait1, &line_wait2};

int main(void)
{
	InitializeQueue(&line1);
	InitializeQueue(&line2);
	
	srand((unsigned int )time (0));
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;
	
	cyc(&line1, 0);
	cyc(&line2, 1);
	
	showrlt(&line1, 0);
	showrlt(&line2, 1);
	
	return 0;
}

void cyc(Queue * pq, int n)
{
	for(cycle = 0; cycle < cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(QueueIsFull(pq))
				(*turnaways[n])++;
			else
			{
				(*customers[n])++;
				tmp = customertime(cycle);
				EnQueue(tmp, pq);
			}
		}
		if ((*wait_time[n]) <= 0 && !QueueIsEmpty(pq))
		{
			DeQueue(&tmp, pq);
			(*wait_time[n]) = tmp.processtime;
			(*line_wait[n]) += cycle - tmp.arrive;
			(*served[n])++;
		}
		if ((*wait_time[n]) > 0)
			(*wait_time[n])--;
		(*sum_line[n]) += QueueItemCount(pq);
	}
}

void showrlt(Queue * pq, int n)
{
	if ((*customers[n]) > 0)
	{
		printf("customers accepted: %ld\n", (*customers[n]));
		printf("customers served: %ld\n", (*served[n]));
		printf("turnaways: %ld\n", (*turnaways[n]));
		printf("average queue size: %.2f\n", (double)(*sum_line[n]) / cyclelimit);
		printf("average wait time: %.2f minutes\n", (double)(*line_wait[n]) / (*served[n]));
	}
	else
		puts("No customers!");
		EmptyTheQueue(pq);
		puts("Bye!");
}

// x = average time, in minutes, between customers 
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;
    
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    
    return cust;
}
