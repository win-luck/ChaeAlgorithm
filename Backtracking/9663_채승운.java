import java.util.*;

public class Main {
	public static int[] arr;
	public static int n;
	public static int result = 0;
	
	public static boolean check(int depth) { // i는 행의 인덱스
		for(int i=0; i<depth; i++) {
			if(arr[i] == arr[depth] || Math.abs(i-depth) == Math.abs(arr[i]-arr[depth])) {
				// arr[i]의 값은 i번째 행에 놓여있는 퀸의 열이 담겨 있다.
				// 첫 번째 조건은 같은 열인 경우를 감지하고,
				// 두 번째 조건은 같은 대각선인 경우를 감지한다.
				// 같은 대각선 -> 두 좌표의 행과 열의 차이가 서로 동일하다
				return false;
			}
		}
		return true; // 검증을 통과했다면 true
	}
	
	public static void dfs(int depth) {		
		if(depth == n) { // 퀸이 총 n개가 배치된다면 (종료조건)			
			result++; // case 하나 추가 후
			return; // 이 탐색은 종료
		} else {	
			for(int i=0; i<n; i++) {
				arr[depth] = i; // 특정 행에 "일단" 퀸 삽입,
				// 행렬 (depth, i)에 퀸이 존재하는 상태에서
				if(check(depth)){ // 퀸 조건 성립 여부 판단하고 만약 성립하면
					dfs(depth+1); // 다음 행으로 넘어감
				}
			}		
		}
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        n = sc.nextInt();
        arr = new int[n];
        dfs(0);  
        System.out.println(result);
    }
    
}