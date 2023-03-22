import IO;

// implicit typecasting
// constructor
// return type
// import statements

class IO{
	public void print_int(int a){
		;
	}
}

class rec1 {
	public int a = 43.3;
	int b;
	int c = 0;

	public int three_times(int a){
		return 2*c;
		// d = 2;
		int newvar = 2;
		// newvar = 2.1;
		return newvar;
	}
	// public int three_times(int a, int b){
	// 	return 2*a+b+a%b;
	// }
}

class rec2 {
	int a = 9;
	int b = 10;

	public int two_times(int a){	
		return 2*a;
	}

	public int sum(int a, int b) {
		int c =  two_times(a + b);
		return sum(a,(int)(a&&b));
		return c;
	}
	int three_times(){
		;
	}
	public void main() {
		IO io = new IO();
		rec1 obj1 = new rec1();
		int a;
		int b = a;
		io.print_int(b);
		float j;
		// int three_times = 4;
		// int c = obj2.sum(obj1.a, 1);

		int c = obj1.three_times(a);
		obj1.three_times(1);
		c = three_times()*4;

		// c =  j;
		double arr[] = new double[10];
		for(int i=0;i<10;i++){
			arr[0] = 1.0;
		}
		// arr = new int[10];
		// io.print_int(j);
	}
}