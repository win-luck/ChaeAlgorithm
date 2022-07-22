import java.util.*;

public class Main {
    public static int[][] d;
    public static int INF=100000000;
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt(); // 도시와 버스의 개수 입력
        d = new int[N+1][N+1];
              
        for(int i=0; i<d.length; i++) {
        	Arrays.fill(d[i], INF);
        	// 최초에 모두가 연결되어 있지 않으므로 INF
        }
        
        for(int a=1; a<=M; a++) {
        	int x = sc.nextInt();
        	int y = sc.nextInt();
        	int input = sc.nextInt();
        	
        	if(input < d[x][y]) {
        		// 버스가 여러개면 가장 작은 것만 입력되도록
        		d[x][y] = input;
        	}
        }
        
       for(int k=1; k<=N; k++) {
    	   for(int i=1; i<=N; i++){
	           	for(int j=1; j<=N; j++) {
	           		if(d[i][j] > d[i][k] + d[k][j]) {
	           			d[i][j] = d[i][k] + d[k][j];
	           		}
	           	}
           }
       } // 플로이드 워셜 알고리즘
       
        for(int i=1; i<=N; i++) {
        	for(int j=1; j<=N; j++) {
        		if(i == j || d[i][j] == INF) {
        			// 만약 출발/도착도시가 같거나, 연결되어 있지 않으면 0
        			System.out.print(0 + " ");
        		} else { 
        			// 그렇지 않으면 보통 출력
        			System.out.print(d[i][j] + " ");
        		}
        	}
        	System.out.println();
        }  
        
    }
}