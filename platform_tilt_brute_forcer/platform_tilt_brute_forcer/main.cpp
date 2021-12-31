#include <iostream>
#include <fstream>
#include "vmath.hpp"
#include "Path.hpp"

std::ofstream out_stream;

int main()
{
    FILE* file = fopen("Platform_Tilts.csv", "w");

    Vec3f marioPos = { -2000.0f, -2950.0f, -600.0f };
    Vec3f platformPos = { -1945.0f, -3225.0f, -715.0f };

    //All the action seems to happen inside this range. Even narrower actually
    float minX = -1911.5f; //platformPos[0] - 500.0f
    float maxX = -1711.5f; //platformPos[0] + 500.0f
    float minZ = -545.0f; //platformPos[2] - 500.0f
    float maxZ = -345.0f; //platformPos[2] + 500.0f

    fprintf(file, "%s\n", "Start Normal X,Start Normal Y,Start Normal Z,Start Mario X,Start Mario Y, Start Mario Z,Best Normal X,Best Normal Y,Best Normal Z,Best Mario X,Best Mario Y,Best Mario Z,Best Frame,Best Boundary Dist");

    BoundaryDistance boundaryDistance = BoundaryDistance();

    for (float startX = minX; startX <= maxX; startX += 0.25f)
    {
        printf("%g\n", startX);

        for (float startZ = minZ; startZ <= maxZ; startZ += 0.25f)
        {
            Vec3f startMarioPos = { startX, -2500.0f, startZ};
            //Vec3f startNormal = { -0.2221239423751831f, 0.8842829847335815f, 0.3479344165325165f }; Normal from triple bully blueprint assuming a 4f 10k route
            Vec3f startNormal = { -0.2221239423751831f, 0.8842829847335815f, 0.3479344165325165f };

            Path path = Path(startMarioPos, startNormal, &boundaryDistance);

            while (path.CurrentFrame != -1 && path.CurrentFrame < 100)
            {
                path.update();
            }

            if (path.BestFrame != -1 && path.BestBoundaryDist > 0.0f)
            {
                fprintf(file, "%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%.50g,%d,%.50g\n",
                    path.StartNormal[0],
                    path.StartNormal[1],
                    path.StartNormal[2],
                    path.StartMarioPos[0],
                    path.StartMarioPos[1],
                    path.StartMarioPos[2],
                    path.BestNormal[0],
                    path.BestNormal[1],
                    path.BestNormal[2],
                    path.BestMarioPos[0],
                    path.BestMarioPos[1],
                    path.BestMarioPos[2],
                    path.BestFrame,
                    path.BestBoundaryDist);
            }
        }
    }

    fclose(file);
}

