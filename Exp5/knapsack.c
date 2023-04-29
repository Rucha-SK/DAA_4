#include<stdio.h>
int capacity[100],value[100];
int n;
int main(){
printf("Enter number of items");
scanf("%d",&n);
printf("Enter capacities/weights\n ");
for(int i=0;i<n;i++){
scanf("%d",&capacity[i]);
}
printf("Enter values\n ");
for(int i=0;i<n;i++){
scanf("%d",&value[i]);
}
printf("\n");
printf("Capacity array={ ");
for(int i=0;i<n;i++){
printf("%d, ",capacity[i]);
}
printf("}\n");
printf("Value array={ ");
for(int i=0;i<n;i++){
printf("%d, ",value[i]);
}

int itemID[n];
for(int i=0;i<n;i++){
    itemID[i]=i;
}
printf("}\n");
int limit;
printf("Enter limit");
scanf("%d",&limit);

float ratio[n];
for(int i=0;i<n;i++){
    ratio[i]=(float)value[i]/(float)capacity[i];
}

printf("Initial table:\n");
printf("ItemId Weight Value  Ratio\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%f\n",itemID[i],capacity[i],value[i],ratio[i]);
}

for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(ratio[i]<ratio[j]){
            float temp=ratio[i];
            ratio[i]=ratio[j];
            ratio[j]=temp;

            int t=capacity[i];
            capacity[i]=capacity[j];
            capacity[j]=t;
            
            t=value[i];
            value[i]=value[j];
            value[j]=t;

            t=itemID[i];
            itemID[i]=itemID[j];
            itemID[j]=t;

        }
    }
}

printf("New table:\n");
printf("ItemId Weight Value  Ratio\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%f\n",itemID[i],capacity[i],value[i],ratio[i]);
}

int ans[n],ele=0;
int cap=0,j=0;
float profit=0.0;
for(int i=0;i<n;i++){
    if(cap+capacity[i]<=limit){
        cap+=capacity[i];
        ans[j]=itemID[i];
        profit+=value[i];
        j++;
    }
    else{
        profit+=((limit-cap)*value[i])/(float)(capacity[i]);
        ans[j]=itemID[i];
        ele=j;
        break;
    }
}
printf("Total profit is:%f\n",profit);
printf("Elements that are included are: ");
for(int i=0;i<=j;i++){
    printf("%d ",ans[i]);
}
return 0;
}