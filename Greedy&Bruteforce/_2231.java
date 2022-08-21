import java.util.*;

public class Main {
	
	public static int checkPos(int i) {
		int sum = 0;	
		
		while(i/10!=0) {
			sum += i%10; // 맨 끝 자릿수 값 더하고
			i/=10; // 맨 끝자리 절삭
		}		
		
		return sum+i; // 마지막 남은 하나의 자릿수 값까지 더해서 반환
	} // 한 수의 각 자릿수들의 합을 계산해주는 함수 checkPos
	
	public static int FindConst(int n) {		
		for(int i=1; i<n; i++) {
			if(i + checkPos(i) == n) {
				// i + i의 각 자릿수들의 합이 n이면 정답
				// 가장 작은 생성자를 구하는 것이므로 더 큰 케이스는 신경쓸 필요가 없음.
				return i;
			}
		}
		return 0; // 생성자가 없다면 0 출력
	} // 생성자를 찾아주는 함수 FindConst
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        int n = sc.nextInt();
        
        System.out.println(FindConst(n));
    }
    
}