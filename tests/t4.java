class rec2 {
	public int two_times(int a){
	// invalid argument list. 
		return 2*a;
	}

	public int sum(int a, int b) {
		int c =  two_times(a + b);
		return c;
	}

	public static void main(String args[]) {
		int a = sum(5, 6);
		System.out.println(a);
		int b = two_times(5);
		System.out.println(b);
		return;
	}

}