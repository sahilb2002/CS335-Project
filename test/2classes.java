import IO;

class rec1 {
	int a = 43;
	int b;
	int c = 0;

	public int three_times(int c){
		return 2*c;
	}
}

class rec2 {
	int a = 9;
	int b = 10;

	public int two_times(int a){	
		return 2*a;
	}

	public int sum(int a, int b) {
		int c =  two_times(a + b);
		return c;
	}

	public void main() {
		IO io = new IO();
		int a;
		int b = a;
		io.print_int(b);

		int c = obj2.sum(obj1.a, 1);

		io.print_int(c);
	}
}