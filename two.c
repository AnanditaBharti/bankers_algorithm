#include<stdio.h>
int main()
{
    int process,res;
    printf("Enter the number of processes : ");
    scanf("%d",&process);
    printf("Enter the number of resources : ");
    scanf("%d",&res);
    int allocation[process][res];
    int max_res[process][res]; 
    int need_res[process][res]; 
    int tot_res[res]; 
    int rem_res[res]; 
    int rem_safe=0;
    int complete[process];
    int sequence[process];
    for(int i=0;i<process;i++)
    {
        printf("Enter the allocated resources for process%d : \n",i+1);
        for(int j=0;j<res;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    for(int i=0;i<process;i++)
    {
        printf("Enter the maximum resources needed for process%d : \n",i+1);
        for(int j=0;j<res;j++)
        {
            scanf("%d",&max_res[i][j]);
            int rem=max_res[i][j]-allocation[i][j];
            need_res[i][j]= ((rem>=0)? rem : 0);
        }
    }
    
    printf("Enter the total amount of all the resources: ");
    for(int i=0 ; i<res ;i++)
    {
        scanf("%d",&tot_res[i]);
    }
    //remainder resources
    for(int i=0;i<res;i++)
    {
        rem_res[i] = 0;
        for(int j=0;j<process;j++)
        {
            rem_res[i] += allocation[j][i];
        }
        rem_res[i] = tot_res[i] - rem_res[i];
    }
    printf("Need matrix :\n  \t");
    for(int j=0;j<res;j++)
    {
        printf("R%d\t",j+1);
    }
    printf("\n");
    for(int i=0;i<process ;i++)
    {
        printf("P%d\t",i+1);
        for(int j=0;j<res;j++)
        {
            printf("%d\t",need_res[i][j]);
        }
        printf("\n");
    }
    int index=0;
    for(int i=0;i<process;i++)
    {
        complete[i]=0;
    }
    while(rem_safe<=process)
    {
        int c=rem_safe;
        int flag=0;
        for(int i=0;i<process;i++)
        {
            
            if(complete[i]==0)
            {
                flag=0;
                for(int j=0;j<res;j++)
                {
                    if(need_res[i][j]>rem_res[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(int k=0;k<res;k++)
                    {
                        rem_res[k] += allocation[i][k];
                    }
                    complete[i] = 1;
                    sequence[index++]=i;    
                }
                rem_safe++;
            }
        }
        if(rem_safe==c)
           break;
    }
    if(rem_safe<=process)
    {
        printf("No safe sequence possible!\n");
        printf("%d\n",rem_safe);
    }
    else
    {
        printf("Safe sequence possible!\nThe sequence would be as follows: ");
        for(int i=0;i<process;i++)
        {
            printf("%d , ",sequence[i]+1);
        }
    }

    return 0;
}