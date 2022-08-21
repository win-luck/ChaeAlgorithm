import java.util.*;

public class Main {
	public static boolean[] visited;
	public static int[] inputarr;
	public static int[] outputarr;
	public static int n,m;
	public static int check = 0;
	
	public static void dfs(int depth) {		
		if(depth == 6) { // 6개의 수열이 모두 생성되었다면?			
			for(int i=0; i<6; i++) {
				System.out.print(outputarr[i]+ " ");
			}
			System.out.println(); // 이들을 출력하고 줄바꿈
		} else {	
			for(int i=0; i<n; i++) {
				if(visited[i] == false && inputarr[i]>check) { // 아직 방문하지 않았고 오름차순 조건이 유지될 때
					visited[i] = true; // 방문하였음을 표시
					outputarr[depth] = inputarr[i]; // 값을 삽입
					dfs(depth+1); // 다음 깊이에 대한 연산
					check = outputarr[depth];
					visited[i] = false; // 현재 노드 기준 자식 방문이 끝나면 다시 그들을 false상태로 만들어주어야 함
				}
			}		
		}
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        
        while(true) {
        	n = sc.nextInt();
        	
        	if(n==0) { // 입력이 0이면 종료
        		break;
        	}                	
        	inputarr = new int[n];
        	outputarr = new int[6];
            visited = new boolean[n];
       	
        	for(int i=0; i<n; i++) {
        		inputarr[i] = sc.nextInt();
        	}
        	
        	dfs(0);  
        	check = 0; // 다음 연산을 위해 비교변수 check를 다시 0으로 초기화
        	System.out.println(); // 줄바꿈
        }
        
    }
}