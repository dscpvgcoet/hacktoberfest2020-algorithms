import java.io.*;
class BinarySearch
{
    void main()throws Exception
    {
        int a[]={};
        int flag= 0,L,U,M=0,n,i,no;   //L->LowerLimit , U->UpperLimit, M->Middle
        L=0;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter array size");
        n=Integer.parseInt(br.readLine());
        a=new int[n];
        System.out.println("Enter array no.s in ascending order");
        for(i=0;i<n;i++)
        a[i]=Integer.parseInt(br.readLine());
        
        System.out.println("Enter no. to be searched");
        no=Integer.parseInt(br.readLine());
        
        U=a.length-1;
        
        while(L<=U)
        {
            M = (L+U)/2;
            if(no > a[M])
                L = M+1; 
            else if(no < a[M])    
                U = M-1;
            else
            {
                flag=1;
                break;
            }   
        }                
        if(flag == 1)
             System.out.println("Element present at position"+(M+1));
        else
             System.out.println("Element not present");
    }
} 