class PascalTriangle{
    public static void main(String[] args) {
        for(int i=0;i<Integer.parseInt(args[0]);++i) {
            for(int j=0;j<=i;++j) {
                System.err.print(v(i,j));
                System.err.print('\t');
            }
            System.err.println();
        }

    }
    static int v(int n, int r) {
        if(n==r||r==0) return 1;
        return v(n-1,r)+v(n-1,r-1);
    }
    
}