const int mod = 1e9 + 7;

const long long mod2 = 1ll * mod * 1ll * mod;

int sz;

struct Matrix{
    int a[301][301];
    Matrix() {
        memset( a, 0, sizeof(a) );
    }
}Base, Tmp;

struct Matrix1xn{
    int a[301];
    Matrix1xn() {
        memset( a, 0, sizeof(a) );
    }
}State;

Matrix mulMatrix(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            long long sum = 0;
            for(int k = 0; k < sz; k++) {
                sum += 1ll * A.a[i][k] * B.a[k][j];
                sum -= ( sum >= mod2 ? mod2 : 0 );
            }
            C.a[i][j] = sum % mod;
        }
    }
    return C;
}

Matrix1xn mulMatrix1xn(Matrix1xn A, Matrix B) {
    Matrix1xn C;
    for(int j = 0; j < sz; j++) {
        long long sum = 0;
        for(int k = 0; k < sz; k++) {
            sum += 1ll * A.a[k] * B.a[k][j];
            sum -= ( sum >= mod2 ? mod2 : 0 );
        }
        C.a[j] = sum % mod;
    }
    return C;
}

Matrix BinPow( Matrix x, int m ) {
    if( m == 1 )
        return x;
    else {
        Tmp = BinPow( x, m / 2 );
        Tmp = mulMatrix( Tmp, Tmp );
        if( m % 2 ) Tmp = mulMatrix( Tmp, Base );
        return Tmp;
    }
}

int Add(int x, int y) {
    return ( 1ll * x + 1ll * y >= mod ? (1ll * x + 1ll * y) % mod : 1ll * x + 1ll * y );
}
