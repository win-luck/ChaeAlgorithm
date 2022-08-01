import java.util.*;

public class Main {
    public static int[][] d;
    public static int INF=100000000; // 
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        d = new int[N+1][N+1];
        
        for(int i=1; i<=N; i++){
        	for(int j=1; j<=N; j++) {
        		d[i][j] = sc.nextInt();
        		if(d[i][j] == 0) {
        			d[i][j] = INF; // 0이면 연결되어 있지 않으므로 INF값 삽입
        		}
        	}
        }
        
       for(int k=1; k<=N; k++) {
    	   for(int i=1; i<=N; i++){
           	for(int j=1; j<=N; j++) {
           		if(d[i][j] > d[i][k] + d[k][j]) { // 최단거리가 갱신된다면 (= INF가 아니라면)
           			d[i][j] = d[i][k] + d[k][j];
           		}
           	}
           }
       }
       
        for(int i=1; i<=N; i++) {
        	for(int j=1; j<=N; j++) {
        		if(d[i][j] == INF) { // 연결된 간선이 없다면 0
        			System.out.print(0 + " ");
        		} else { // 있으면 1
        			System.out.print(1 + " ");
        		}
        	}
        	System.out.println();
        }
      
        
    }
}