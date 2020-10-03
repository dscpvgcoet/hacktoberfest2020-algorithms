import java.io.*;
class search
{
    void main()throws Exception
    {
        int a[]={},i,flag=0,n,no;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter array size");
        n=Integer.parseInt(br.readLine());
        a=new int[n];
        System.out.println("Enter array no.s");
        for(i=0;i<n;i++)
        a[i]=Integer.parseInt(br.readLine());
        System.out.println("Enter no. to be searched");
        no=Integer.parseInt(br.readLine());
        for(i=0;i<n;i++)
        {
            if(no==a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            System.out.println("Element present at"+(i+1));
        }
        else
        {
            System.out.println("Element not present");
        }
    }
}
    