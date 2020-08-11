
// BOJ 1644 소수의 연속합 Java

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int n=Integer.parseInt(br.readLine()),start,rear,sum,ans;
		boolean isNotPrime[]=new boolean[n+10];
		isNotPrime[1]=true;
		for(int i=2;i<=n+9;++i)
			if(!isNotPrime[i])
				for(int j=i*2;j<=n+9;j+=i)
					isNotPrime[j]=true;
		start=2;
		rear=3;
		sum=start+rear;
		ans=isNotPrime[n]?0:1;
		while(start<rear) {
			if(sum>=n) {
				if(sum==n) ++ans;
				sum-=start;
				++start;
				while(isNotPrime[start]) ++start;
			}
			else {
				++rear;
				while(isNotPrime[rear]) ++rear;
				sum+=rear;
			}
		}
		bw.write(Integer.toString(ans));
		bw.flush(); bw.close(); br.close();
		return;
	}
}
