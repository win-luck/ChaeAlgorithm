import java.util.*;

public class Main {
	public static boolean[] visited;
	public static int[] arr;
	public static int n,m;

	public static void dfs(int depth) {		
		if(depth == m) { // m개의 수열이 모두 생성되었다면?			
			for(int i=0; i<m; i++) {
				System.out.print(arr[i]+ " ");
			}
			System.out.println(); // 이들을 출력하고 줄바꿈
		} else {	
			for(int i=0; i<n; i++) {
				if(visited[i] == false) { // 아직 방문하지 않았을 때
					visited[i] = true; // 방문하였음을 표시
					arr[depth] = i+1; // 값을 삽입
					dfs(depth+1); // 다음 깊이에 대한 연산 실시
					visited[i] = false; // 현재 노드 기준 자식 방문이 끝나면 다시 그들을 false상태로 만들어주어야 함
				}
			}			
		}
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        n = sc.nextInt(); // 1부터 n까지의 자연수
        m = sc.nextInt(); // 중복 없이 m개를 고른 수열
        visited = new boolean[n];
        arr = new int[m];
        dfs(0);
    }
}