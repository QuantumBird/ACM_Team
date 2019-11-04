import java.math.*;
import java.util.*;
public class POJ_3982{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            BigInteger[] num = new BigInteger[100];
            num[0] = cin.nextBigInteger();
            num[1] = cin.nextBigInteger();
            num[2] = cin.nextBigInteger();
            for(int i=3;i<=99;++i){
                num[i] = num[i-1].add(num[i-2]).add(num[i-3]);
            }
            System.out.println(num[99]);
        }
    }
}
