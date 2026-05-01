// priority.c
#include <stdio.h>

int main(){
    int n,i,j;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int bt[n], pr[n], ct[n], tat[n], wt[n];

    for(i=0;i<n;i++){
        printf("BT and Priority of P%d: ",i+1);
        scanf("%d %d",&bt[i],&pr[i]);
    }

    // Sort by priority (lower = higher priority)
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pr[i]>pr[j]){
                int temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
            }
        }
    }

    ct[0]=bt[0];
    for(i=1;i<n;i++)
        ct[i]=ct[i-1]+bt[i];

    float avg_wt=0, avg_tat=0;

    for(i=0;i<n;i++){
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        printf("P%d: CT=%d TAT=%d WT=%d\n",i+1,ct[i],tat[i],wt[i]);
    }

    printf("Avg WT=%.2f\nAvg TAT=%.2f",avg_wt/n,avg_tat/n);
}