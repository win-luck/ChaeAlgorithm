import java.util.*;

public class Main{
		
	public static boolean[] check = new boolean[1000003];
	
	public static void main(String[] args){
		      Scanner sc = new Scanner(System.in);
		      long min = sc.nextLong();
		      long max = sc.nextLong();
		      int count = 0;
		      
		      // 에라스토테네스의 체 변형
		      for(long i=2; i*i<=max; i++){
		    	  long num = min / (i * i); // 일단 min을 i*i로 나누어 몫을 구함.
                
		    	  if (min % (i * i) != 0) {
		    		  num++;
		    	  }
		    	  // 만약 min이 i*i로 나누어떨어지지 않는다면 num에 하나 더해준다.
		    	  // 예를 들어 min이 30, i=2인 경우, 30 / 4 = 7이다.
		    	  // 그러나, 7*2*2 = 28은 min과 max 사이의 범위가 아니다. 그러므로 num+1

		    	  while (num * i * i <= max) { // i*i로 나누어떨어지는 모든 수를 max와 min 사이에서 찾아내어 표시
		    		  check[(int) (num * i * i - min)] = true; // 이들은 제곱ㄴㄴ수가 아님
		    		  num++;
		    	  }
		      }    
		      
		      for (int i = 0; i <= max - min; i++) {
	                if (!check[i]) count++; // 제곱ㄴㄴ수가 총 몇 개인지 계산
		      }
		      
		      System.out.println(count);
	}
}