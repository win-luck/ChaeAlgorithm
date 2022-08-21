import java.util.*;
import java.io.*;

public class Main {
	public static int N;
	public static int[][] map;
	public static int[][] visited;
	public static int[] xmove = {1, 2, 2, 1, -1, -2, -2, -1};
	public static int[] ymove = {2, 1, -1, -2, -2, -1, 1, 2};
	
	static class Dot { // 좌표 표현을 위한 클래스 Dot
		int x;
		int y;
		public Dot(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static int BFS(int inputx, int inputy, int targetx, int targety) {
		Queue<Dot> q = new LinkedList<Dot>();
		q.add(new Dot(inputx, inputy));
		visited[inputx][inputy] = 1; // 일단 첫번째 이동을 대비해서 첫 좌표의 visited값 +1
		
		while(q.size()!=0) {
			Dot dot = q.poll();
			
			for(int i=0; i<8; i++) {
				int tempx = dot.x + xmove[i];
				int tempy = dot.y + ymove[i]; // 8칸 순회
				
				if(tempx == targetx && tempy == targety) { // 만약 그 칸이면
					return visited[dot.x][dot.y]; // 방문 횟수 출력
				}
				
				if(tempx>=0 && tempy>=0 && tempx<N && tempy<N) {
					if(visited[tempx][tempy] == 0) { // 아직 방문하지 않았다면
						visited[tempx][tempy] = visited[dot.x][dot.y]+1; // +1
						q.add(new Dot(tempx, tempy)); // 그 좌표를 다시 큐에 담고 BFS
					}
					
				}
			}			
		}
		return 0;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int testcase = sc.nextInt(); // 시행 횟수
		
		for(int i=0; i<testcase; i++) {
			N = sc.nextInt();
			visited = new int[N][N];
			map = new int[N][N];
			
			int inputx = sc.nextInt();
			int inputy = sc.nextInt(); // 입력 좌표
			int targetx = sc.nextInt();
			int targety = sc.nextInt(); // 목표 좌표
			
			if(inputx == targetx && inputy == targety) {
				System.out.println(0);
				continue;
			} // 만약 자기 자신이면 BFS 진행할 필요도 없음
			
			System.out.println(BFS(inputx, inputy, targetx, targety));
		}
		
	}
	
}