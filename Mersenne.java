class Mersenne {
    static {
	System.loadLibrary("mersenne_jni");
    }

    private native static long mersenne(long index);

    public static final void main(String args[]) {
	for (long i = 0; i < 50; i++) {
	    System.out.println("" + i + ": " + mersenne(i));
	}
    }
}
