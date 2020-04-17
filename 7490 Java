
// BOJ 7490 0 만들기 Java

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.*;

public class Main {
	public static void brute_force(int n,int pos,int val,int add,int mp,String ans) {
		if(pos==n) {
			val+=(add*mp);
			if(val==0) {
				System.out.println(ans);
				return;
			}
			return;
		}
		brute_force(n,pos+1,val,add*10+pos+1,mp,ans+" "+Integer.toString(pos+1));
		brute_force(n,pos+1,val+add*mp,pos+1,1,ans+"+"+Integer.toString(pos+1));
		brute_force(n,pos+1,val+add*mp,pos+1,-1,ans+"-"+Integer.toString(pos+1));
        return;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine()),n;
		for(int i=0;i<tc;++i) {
			n=Integer.parseInt(br.readLine());
			brute_force(n,1,0,1,1,"1");
			System.out.println();
		}
		br.close();
		return;
	}
}
