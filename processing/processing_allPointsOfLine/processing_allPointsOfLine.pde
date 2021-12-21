PVector plist [] = new PVector [4];

void setup() {
  size(400, 400);
  plist[0] = new PVector(84, 91);
  plist[1] = new PVector(68, 19);
  plist[2] = new PVector(21, 17);
  plist[3] = new PVector(32, 100);
}
void draw() {
  background(200);
  noFill();
  beginShape();
  curveVertex(plist[0].x, plist[0].y);
  curveVertex(plist[0].x, plist[0].y);
  curveVertex(plist[1].x, plist[1].y);
  curveVertex(plist[2].x, plist[2].y);
  curveVertex(plist[3].x, plist[3].y);
  curveVertex(plist[3].x, plist[3].y);
  endShape();
  for (int i = 0; i< plist.length; i ++) {
    ellipse(plist[i].x, plist[i].y, 6, 6);
  }
  float lerpPoint = map(mouseX, 0, width, 1, 0);
  PVector pointOnCurve = getCurveVertexPoint(plist[0], plist[1], plist[2], plist[3], lerpPoint);
  ellipse(pointOnCurve.x, pointOnCurve.y, 12, 12);
}

PVector getCurveVertexPoint(PVector P0, PVector P1, PVector P2, PVector P3, float t) {
  float alpha = 0.5;
  float px = alpha * ((2 * P1.x) + (-P0.x+P2.x) * t + (2 * P0.x-5 * P1.x + 4*P2.x - P3.x) * (t * t) + (-P0.x + 3 * P1.x-3 * P2.x + P3.x) * (t * t * t)) ;
  float py = alpha * ((2 * P1.y) + (-P0.y+P2.y) * t + (2 * P0.y-5 * P1.y + 4*P2.y - P3.y) * (t * t) + (-P0.y + 3 * P1.y-3 * P2.y + P3.y) * (t * t * t)) ;
  PVector returnVector = new PVector(px, py);
  return returnVector;
}
