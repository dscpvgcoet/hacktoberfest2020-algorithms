import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        String str = scn.nextLine();
        HashMap<Character,Integer> hm = new HashMap<>();
        
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(hm.containsKey(ch)){
                int oldFrequency = hm.get(ch);
                int newFrequency = oldFrequency +1;
                hm.put(ch,newFrequency);
            }else{
                hm.put(ch,1);
            }
        }
        
         char maxCharacterFrequency = str.charAt(0);
        for(Character key: hm.keySet()){
           
            if(hm.get(key) > hm.get(maxCharacterFrequency)){
                maxCharacterFrequency = key;
            }
        }
        System.out.println(maxCharacterFrequency);
    }

}
