import java.util.*;

public class Main{
		
	public static void main(String[] args){
		      Scanner sc = new Scanner(System.in);
		      long N = sc.nextLong();
		      StringBuilder sb = new StringBuilder();
		      
		      long r=2, n=3, input=0; // 공비는 2부터, 항의 개수는 3부터 시작, input은 등비수열의 항이 임시적으로 담김
		      boolean flag = false; // 등비수열의 존재 여부 확인용 변수
		     
		      // 등비수열의 합 공식 a * (r^n-1) / (r-1) = N
		      while(r<1000000) { // 먼저 공비를 결정
		    	  // n이 최소 3인 상황에서, 공비가 10^6보다 크거나 같다면 
		    	  // 등비수열의 합인 N이 10^12를 넘어가므로 조건 이탈
		    	  n = 3; // n은 최소 3개
		    	  input = r * r * r; // input은 r^n의 역할을 맡음
		    	  
		          while(n<=40) { // 항의 개수를 늘려나가고 등비수열을 확장하며 그 합이 N이 되는 경우를 탐색
		        	  // a=1, r=2라고 가정하면, 2^n-1 = 10^12라는 식을 도출,
		        	  // n이 40일 때까지는 저 경계를 넘지 않으므로 항의 개수는 최대 40개이다.
			    	  if(N * (r-1) % (input-1) == 0) { 
			    		  // a * (r^n-1) / (r-1) = N 식에서, 초항이 input(r^n)으로 나누어떨어진다면 N은 등비수열의 합이 된다.
			    		  flag = true;
			    		  break;
			    	  }
			    	 			    	  
			    	  if(input>1e12) { // 등비수열의 요소들이 10의 12제곱을 넘기면 안 됨!
			    		  break;
			    	  }
			    	  
			    	  input *= r; // 다음 항 생성
			    	  n++; // 항 추가
			      }
		          
		    	  if(flag) { // 조건에 맞는 등비수열 발견
		    		  break;
		    	  }
		    	  r++; // 다음 공비로 이동
		      }
		
		      if(!flag) { // 조건에 맞는 등비수열이 없다!
		    	  System.out.println(-1);
		      } else { // 있다!
		    	  sb.append(n + "\n"); // 등비수열의 개수
		    	  long a = N * (r-1) / (input-1); // 등비수열의 초항 (등비수열의 합 공식 변형)
		    	  for(int i=1; i<=n; i++) {
		    		  sb.append(a+ " "); 
		    		  a*=r; // 등비수열 출력
		    	  }
		      }
		      
		      System.out.println(sb.toString());
	}
}