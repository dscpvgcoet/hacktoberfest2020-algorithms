import java.io.*;
class SelectionSort
{
    void main()throws Exception
    {
        int a[]={},i,c,j,n;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter array size");
        n=Integer.parseInt(br.readLine());
        a=new int[n];
        System.out.println("Enter array no");
        for(i=0;i<n;i++)
        a[i]=Integer.parseInt(br.readLine());
        
         for(i=0;i<a.length;i++)
        {
            for(j=i+1;j<a.length;j++)
            if(a[i]>a[j])
            {
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
        System.out.println("Elements after sorting :");        
        for(i=0;i<a.length;i++)
        System.out.println(a[i]);        
        
    }
} 