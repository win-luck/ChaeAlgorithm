import java.util.*;

public class Main {
    public static int[][] d;
    public static int INF=100000000;
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        d = new int[N+1][N+1];
        
        for(int a=1; a<=M; a++) {
        	int x = sc.nextInt();
        	int y = sc.nextInt();
        	d[x][y] = 1; // 연결되었음을 의미 (키를 알 수 있음)
        }
        
       for(int k=1; k<=N; k++) {
    	   for(int i=1; i<=N; i++){
	           	for(int j=1; j<=N; j++) {
	           		if(d[i][k] == 1 && d[k][j] == 1) {
	           			d[i][j] = 1; // 경유해서 연결된다면 당연히 갱신
	           		}
	           	}
           }
       } // 플로이드 워셜 알고리즘
       
       int num = 0;     
        for(int i=1; i<=N; i++) {
        	boolean check = true; // 체크표시
        	
        	for(int j=1; j<=N; j++) {
        		if(i==j) { // 자기 자신은 안 됨.
        			continue;
        		}
        		
        		if(d[i][j] != 1 && d[j][i] != 1) {
        		// 연결될 수 없는 친구(키를 알 수 없는 친구)가 존재한다면?
        		// 이 친구는 자신의 키 순위를 확정할 수 없음.
        			check = false;
        			break;
        		}
        	}       	
        	if(check) { // 테스트를 통과했다면 이 친구는 자신의 키 순위를 확정지을 수 있음
        		num++;
        	}
        }
        System.out.println(num);
    }
}