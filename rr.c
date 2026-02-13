#include <stdio.h>
int main() {
    int n, tq, bt[10], at[10], rt[10], ct[10], tat[10], wt[10];
    int i, time = 0, remain;
    float avg_tat = 0, avg_wt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) scanf("%d", &at[i]);
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    while (remain > 0) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
        if (done) time++; 
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("\nAverage TAT = %.2f", avg_tat);
    printf("\nAverage WT  = %.2f\n", avg_wt);
    return 0;
}
