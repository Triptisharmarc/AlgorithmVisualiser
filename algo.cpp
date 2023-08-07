#include <bits/stdc++.h>
using namespace std;
#define max 20
#include<graphics.h>
#include<conio.h>

void arrayy(int n)
{
    int i;
    
    setlinestyle(0, 0, 3);
    setcolor(YELLOW);
    setbkcolor(5);
    setfillstyle(SOLID_FILL,5);
    floodfill(150,300,6);
    setcolor(LIGHTCYAN);
    settextstyle(4,HORIZ_DIR,50);
    //settextstyle(BOLD_FONT,HORIZ_DIR,50);
    outtextxy(460,0,"Algorithm Visualiser");
    setcolor(YELLOW);
    
    line(450, 50, 1100, 50);
    line(100, 250, 100, 350);
    for (i = 0; i < n; i++)
    {
        line(100 + (100 * i), 250, 200 + (100 * i), 250);
        line(100 + (100 * i), 350, 200 + (100 * i), 350);
        line(200 + (100 * i), 250, 200 + (100 * i), 350);
    }
    
}

void printArray(int arr[], int size)
{
    int i;
    char a[5];
    settextstyle(6,HORIZ_DIR,15);
    for (i = 0; i < size; i++)
        {
        cout <<" "<< arr[i];
        setbkcolor(5);
        //setfillstyle(SOLID_FILL,5);
        
        
    
        sprintf(a,"%d",arr[i]);
        outtextxy(130+(100*i),290,a);}
       
}

void printele(int arr[], int j)
{
    setcolor(15);
    char a[5];
    settextstyle(6,HORIZ_DIR,15);
    sprintf(a,"%d",arr[j]);
    outtextxy(130+(100*j),290,a);
    sprintf(a,"%d",arr[j+1]);
    outtextxy(130+(100*(j+1)),290,a);
    
}




class sorting{
    public:

    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void bubbleSort(int arr[], int n)
    {
       int i, j;
       char a[5];
       bool swapped;
       for (i = 0; i < n-1; i++)
       {
        
        
        swapped = false;
        sprintf(a,"Pass %d",i+1);
        outtextxy(120,450,a);
         for (j = 0; j < n-i-1; j++)
         {
            if (arr[j] > arr[j+1])
            {
               
               swap(&arr[j], &arr[j+1]);
               swapped = true;
               setcolor(YELLOW);
               delay(2000);
               setcolor(15);
               printele(arr,j);
              
               delay(2000);
               setcolor(5);
               rectangle(110,260,190,340);
               //floodfill(110,260,6);
               setcolor(14);
               printArray(arr,n);
               
            }
            
        }
      
        
        
         // IF no two elements were swapped
         // by inner loop, then break
         if (swapped == false)
            break;
       }
       
       arrayy(n);
    }
    void insertionSort(int array[], int size) {
        char a[5];
        setcolor(14);
        for (int i = 1; i < size; i++) {
        int key = array[i];
        //sprintf(a,"Step %d",i);
        //outtextxy(120,450,a);
        int j = i - 1;
        setcolor(14);
        printArray(array,size);
        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
          array[j + 1] = array[j];
          --j;
        
        }
        //setcolor(15);
        //printele(array,j);
        delay(3500);
        array[j + 1] = key;
        
      }
      setcolor(YELLOW);
      arrayy(size);
    }
    
    
    void printele1(int arr[], int j,int n)
    {
        setcolor(15);
        char a[5];
        settextstyle(6,HORIZ_DIR,15);
        sprintf(a,"%d",arr[j]);
        outtextxy(130+(100*j),290,a);
        sprintf(a,"%d",arr[j+1]);
        outtextxy(130+(100*(j+1)),290,a);
        setfillstyle(SOLID_FILL,5);
        bar(100+(100*n),250,400+(100*n),350);
        
    }
    
    
    
    
    void selectionSort(int arr[], int n)
    {
        int i, j, min_idx;
     
        // One by one move boundary of
        // unsorted subarray
        for (i = 0; i < n-1; i++)
        {
           
            // Find the minimum element in
            // unsorted array
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                min_idx = j;
     
            // Swap the found minimum element
            // with the first element
            if(min_idx!=i)
                
                swap(&arr[min_idx], &arr[i]);
                //swap(arr[j], arr[j+1]);
               
               setcolor(YELLOW);
               delay(2000);
               setcolor(15);
               printele1(arr,min_idx,n);
              
               delay(4000);
               //rectangle(110,260,200,340);
               //floodfill(110,260,6);
               setcolor(14);
               printArray(arr,n);
               setfillstyle(SOLID_FILL,5);
            bar(100+(100*n),250,400+(100*n),350);
                
        }
    }
};
int main()
{
    system("cls");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "", -3, -3);
    
    int arr[max],i,n;
    
    sorting S;
    int ch;
    
    do{
        cout<<("\nenter the size of array");
    cin>>n;
    cout<<("enter the elements of array\n");
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arrayy(n);
    
        cout<<"\n1.Bubble sort \n2.Insertion sort \n3.Selection sort \n";
        cout<<"Choose the type of sorting";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                setcolor(14);
                settextstyle(3,HORIZ_DIR,27);
                outtextxy(70,150,"BUbble sort");
                printArray(arr, n);
                S.bubbleSort(arr, n);
                cout <<"Sorted array: \n";
                settextstyle(3,HORIZ_DIR,27);
                outtextxy(70,150,"BUbble sort");
                printArray(arr, n);
                break;
                
            case 2:
                setcolor(14);
                settextstyle(3,HORIZ_DIR,27);
                outtextxy(70,150,"Insertion sort");
                printArray(arr, n);
                S.insertionSort(arr, n);
                cout <<"Sorted array: \n";
                printArray(arr, n);
                outtextxy(70,150,"Insertion sort");
                settextstyle(6,HORIZ_DIR,15);
                outtextxy(120,450,"Sorted array");
                //array(n);
                break;
                
            case 3:
                setcolor(14)    ;
                settextstyle(3,HORIZ_DIR,27);
                outtextxy(70,150,"Selection sort");
                printArray(arr, n);
                S.selectionSort(arr, n);
                cout <<"Sorted array: \n";
                printArray(arr, n); 
                arrayy(n);
                settextstyle(3,HORIZ_DIR,27);
                outtextxy(70,150,"Selection sort"); 
                settextstyle(6,HORIZ_DIR,15);
                outtextxy(120,450,"Sorted array");
                printArray(arr,n);
        }
    }while(ch!=4);
    getch();
}
