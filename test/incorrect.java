import IO;

class rec1 {
	int a = 43;

	public int three_times(int c){
		return 2*c;
	}
}

class rec2 {
	int a = 9;
	int b = 10;

	public int two_times(int){
	// invalid argument list. 
		return 2*a;
	}

	public int sum(int a, int b) {
		int c =  two_times(a + b);
		return c;
	}

}