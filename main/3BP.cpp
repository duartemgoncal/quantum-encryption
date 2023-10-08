#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Body {
    double mass;
    vector<double> position;
    vector<double> velocity;
    vector<double> acceleration;
};

int main(){
    const double G = 1;
    const double dt = 0.001;
    const double tmax = 1000;
    const int N = tmax/dt;
    
    vector<Body> bodies;
    Body body1;
    Body body2;
    Body body3;
    body1.mass = 1;
    body2.mass = 2;
    body3.mass = 10;
    body1.position = {0,0,3.99999};
    body2.position = {1,2,0};
    body3.position = {7,0,0};
    body1.velocity = {0,0,0};
    body2.velocity = {5,0,0};
    body3.velocity = {10,0,0};
    body1.acceleration = {0,0,0};
    body2.acceleration = {0,0,0};
    body3.acceleration = {0,0,0};
    bodies.push_back(body1);
    bodies.push_back(body2);
    bodies.push_back(body3);

    vector<double> vt, vm1x, vm1y, vm1z, vm1vx, vm1vy, vm1vz, vm2x, vm2y, vm2z, vm2vx, vm2vy, vm2vz, vm3x, vm3y, vm3z, vm3vx, vm3vy, vm3vz;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < bodies.size(); j++){
            for(int k = 0; k < bodies.size(); k++){
                if(j != k){
                    double r = sqrt(pow(bodies[j].position[0]-bodies[k].position[0],2)+pow(bodies[j].position[1]-bodies[k].position[1],2)+pow(bodies[j].position[2]-bodies[k].position[2],2));
                    bodies[j].acceleration[0] += -G*bodies[k].mass*(bodies[j].position[0]-bodies[k].position[0])/pow(r,3);
                    bodies[j].acceleration[1] += -G*bodies[k].mass*(bodies[j].position[1]-bodies[k].position[1])/pow(r,3);
                    bodies[j].acceleration[2] += -G*bodies[k].mass*(bodies[j].position[2]-bodies[k].position[2])/pow(r,3);
                }
            }
        }
        for(int j = 0; j < bodies.size(); j++){
            bodies[j].velocity[0] += bodies[j].acceleration[0]*dt;
            bodies[j].velocity[1] += bodies[j].acceleration[1]*dt;
            bodies[j].velocity[2] += bodies[j].acceleration[2]*dt;
            bodies[j].position[0] += bodies[j].velocity[0]*dt;
            bodies[j].position[1] += bodies[j].velocity[1]*dt;
            bodies[j].position[2] += bodies[j].velocity[2]*dt;
            bodies[j].acceleration[0] = 0;
            bodies[j].acceleration[1] = 0;
            bodies[j].acceleration[2] = 0;
            vt.push_back(i*dt);
            if(j == 0){
                vm1x.push_back(bodies[j].position[0]);
                vm1y.push_back(bodies[j].position[1]);
                vm1z.push_back(bodies[j].position[2]);
                vm1vx.push_back(bodies[j].velocity[0]);
                vm1vy.push_back(bodies[j].velocity[1]);
                vm1vz.push_back(bodies[j].velocity[2]);
            }
            else if(j == 1){
                vm2x.push_back(bodies[j].position[0]);
                vm2y.push_back(bodies[j].position[1]);
                vm2z.push_back(bodies[j].position[2]);
                vm2vx.push_back(bodies[j].velocity[0]);
                vm2vy.push_back(bodies[j].velocity[1]);
                vm2vz.push_back(bodies[j].velocity[2]);
            }
            else if(j == 2){
                vm3x.push_back(bodies[j].position[0]);
                vm3y.push_back(bodies[j].position[1]);
                vm3z.push_back(bodies[j].position[2]);
                vm3vx.push_back(bodies[j].velocity[0]);
                vm3vy.push_back(bodies[j].velocity[1]);
                vm3vz.push_back(bodies[j].velocity[2]);
            }
        }
    }
    for(int i = 0; i < bodies.size(); i++){
        cout << "Body " << i+1 << " position: (" << bodies[i].position[0] << "," << bodies[i].position[1] << "," << bodies[i].position[2] << ")" << endl;
        cout << "Body " << i+1 << " velocity: (" << bodies[i].velocity[0] << "," << bodies[i].velocity[1] << "," << bodies[i].velocity[2] << ")" << endl;
    }
    double p = 1;
    for (int i = 0; i < bodies.size(); i++){
        for (int j = 0; j < 3; j++){
            p *= bodies[i].position[j];
            p *= bodies[i].velocity[j];
        }
    }
    cout << "Product: " << p << endl;
    return 0;
}