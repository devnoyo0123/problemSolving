#include <iostream>
using namespace std;
void convert(int num, int base) {
    if (num == 0) return;
    cout<<"num:"<<num<<" ,base: "<<base<<"\n";
    convert(num/base, base);
    printf("%d ",num%base);
}
int main() {
    int a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ans = ans * a + x;
    }
    cout<<"ans: "<<ans<<"\n";
    convert(ans,b);
    return 0;
}