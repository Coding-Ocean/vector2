#include"libOne.h"
class VEHICLE {
public:
    VEHICLE(float x, float y) {
        target.x = x;
        target.y = y;
        pos.x = random(width);
        pos.y = random(height);
        float deg = random()%360;
        vel.x = cos(deg) * 20;
        vel.y = sin(deg) * 20;
        r = 8;
        maxspeed = 10;
        maxforce = 1;
    }
    VECTOR2 arrive() {
        VECTOR2 desired = target - pos;
        float d = length(desired);
        float speed = maxspeed;
        if (d < 100) {
            speed = map(d, 0, 100, 0, maxspeed);
        }
        desired /= d;
        desired *= speed;
        VECTOR2 steer = desired - vel;
        d = length(steer);
        if (d > maxforce) {
            steer /= d;
            steer *= maxforce;
        }
        return steer;
    }

    VECTOR2 target;
    VECTOR2 pos;
    VECTOR2 vel;
    VECTOR2 acc;
    float r;
    float maxspeed;
    float maxforce;
};

/*
Vehicle.prototype.behaviors = function() {
    arrive = this.arrive(this.target);
    this.applyForce(arrive);

    mouse = createVector(mouseX, mouseY);
    flee = this.flee(mouse);
    this.applyForce(flee);
}
Vehicle.prototype.arrive = function(target) {
    desired = p5.Vector.sub(target, this.pos);
    d = desired.mag();
    speed = this.maxspeed;
    if (d < 100) {
        speed = map(d, 0, 100, 0, this.maxspeed);
    }
    desired.setMag(speed);
    steer = p5.Vector.sub(desired, this.vel);
    steer.limit(this.maxforce);
    return steer;
}
Vehicle.prototype.flee = function(target) {
    desired = p5.Vector.sub(target, this.pos);
    d = desired.mag();
    //steer.mult(0); 
    if (d < 80) {
        desired.setMag(this.maxspeed);
        desired.mult(-1);
        steer = p5.Vector.sub(desired, this.vel);
        steer.limit(this.maxforce);
        steer.mult(10);
    }
    return steer;
}
Vehicle.prototype.applyForce = function(f) {
    this.acc.add(f);
}

Vehicle.prototype.update = function() {
    this.pos.add(this.vel);
    this.vel.add(this.acc);
    this.acc.mult(0);
}

Vehicle.prototype.show = function() {
    stroke(255);
    strokeWeight(this.r);
    point(this.pos.x, this.pos.y);
}
*/
void gmain() {
    window(1000, 1000);
    VECTOR2 playerPos(25,25);
    VECTOR2 playerVel(0, 0);
    VECTOR2 enemyPos(300,200);
    while (notQuit){
        enemyPos.x = mouseX;
        enemyPos.y = mouseY;
        playerPos += playerVel;
        VECTOR2 playerAcc = enemyPos - playerPos;
        playerVel += playerAcc;
        clear(220);
        fill(160, 200, 255);
        circle(playerPos.x, playerPos.y, 50);
        fill(128);
        circle(enemyPos.x, enemyPos.y, 50);

        line(playerPos.x, playerPos.y, 
            playerPos.x + playerVel.x, playerPos.y + playerVel.y);
    }
}