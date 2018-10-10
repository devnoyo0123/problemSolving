#include <cstdio>

const int MAX = 11;

typedef struct Magnetic
{
    double x;
    double power;
}Magenetic;

int main(int argc, char** argv)
{
    int T;

    scanf("%d", &T);


    for (int tc = 1; tc <= T; tc++)
    {
        double ans[MAX];
        Magenetic magnetic[MAX];

        int N;

        scanf("%d", &N);

        double minX = 0, maxX = 987654321;

        for (int i = 0; i < N; i++)
        {
            scanf("%lf %lf", &magnetic[i].x, &magnetic[i].power);
        }

        for (int i = 0; i < N - 1; i++)
        {
            double minX = magnetic[i].x;
            double maxX = magnetic[i + 1].x;

            while (maxX - minX > 1e-12)
            {
                double mid = (maxX + minX) / 2;

                double nowPower = 0;

                for (int i = 0; i < N; i++)
                {
                    nowPower += (magnetic[i].power / (magnetic[i].x - mid)
                            / (magnetic[i].x - mid)) * ((magnetic[i].x < mid) ? -1 : 1 );
                }

                if (nowPower > 0.0)
                {
                    maxX = mid;

                }
                else if ( nowPower < 0.0)
                {
                    minX = mid;
                }
                else
                {
                    minX = mid;
                    maxX = mid;
                }
            }

            ans[i] = (maxX + minX) / 2;
        }

        printf("#%d ", tc);
        for (int i = 0; i < N - 1; i++)
        {
            printf("%.10lf ", ans[i]);
        }
        printf("\n");
    }



    return 0;
}