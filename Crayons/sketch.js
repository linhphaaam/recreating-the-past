// a shader variable


let theShader;
let capture;
let rock_img;
let line_img;
let face_img;
let contour_img;
var w = 1024;
var h = 800;

function preload(){
  // load the shader
  theShader = loadShader('shader.vert', 'shader.frag');
  rock_img = loadImage('assets/rock.jpg');
  line_img = loadImage('assets/frida_1.jpg');
}

function setup() {
  // disables scaling for retina screens which can create inconsistent scaling between displays
  pixelDensity(1);
  
  // shaders require WEBGL mode to work
  createCanvas(w, h, WEBGL);
  noStroke();
  capture = createCapture(VIDEO);
  capture.size(w, h);

  face_img = capture.get(0, 0, capture.width, capture.height); 
  
  
  // cam.hide();
}


var captureMat, gray, blurred, thresholded;
var contours, hierarchy, color_scalar;

function cvSetup() {
  captureMat = new cv.Mat([h, w], cv.CV_8UC4);
  gray = new cv.Mat([h, w], cv.CV_8UC1);
  blurred = new cv.Mat([h, w], cv.CV_8UC1);
  thresholded = new cv.Mat([h, w], cv.CV_8UC1);
  
}

var ready = false;

function cvReady() {
  if(!cv || !cv.loaded) return false;
  if(ready) return true;
  cvSetup();
  ready = true;
  return true;
}



function draw() {  

  background(255);
  var showThresholded = select('#showThresholded').checked();
  
  if (cvReady()) {
    capture.loadPixels();  
    if (pixels.length > 0) {
      // console.log('test'); 
  
    // for (let x = 0; x < capture.width; x++) {
    //   for (let y = 0; y < capture.height; y++) {
    //     let i = (x + y * capture.width) * 4;
    //     let r = pixels[i+0];
    //     let g = pixels[i+1];
    //     let b = pixels[i+2];
    //     let a = pixels[i+3];
        
    //     let pixelColor;
    //     // console.log(g);
    //     if ((g / 255) > 0.5) {
    //       pixelColor = 255;
    //     } else {

    //       pixelColor = 0;
    //     }
        
    //     pixels[i+0] = pixelColor;
    //     pixels[i+1] = pixelColor;
    //     pixels[i+2] = pixelColor;
    //   }
    // }
    // capture.updatePixels(); 
      captureMat.data().set(pixels);

      var blurRadius = select('#blurRadius').value();
      blurRadius = map(blurRadius, 0, 100, 1, 10);

      var threshold = select('#threshold').value();
      threshold = map(threshold, 0, 100, 0, 255);

      cv.cvtColor(captureMat, gray, cv.ColorConversionCodes.COLOR_RGBA2GRAY.value, 0);
      cv.blur(gray, blurred, [blurRadius, blurRadius], [-1, -1], cv.BORDER_DEFAULT);
      cv.threshold(blurred, thresholded, threshold, 255, cv.ThresholdTypes.THRESH_BINARY.value);



      // if (showThresholded) {
      var src = thresholded.data();
      // var dst = capture.pixels;
      var n = src.length;
      var j = 0;
      
      for (var i = 0; i < n; i++) {
        pixels[j++] = src[i];
        pixels[j++] = src[i];
        pixels[j++] = src[i];
        pixels[j++] = 255;
        }
      capture.updatePixels();

    }
    // face_img = capture.get(0, 0, capture.width, capture.height);
    // let dst = new cv.Mat.zeros(src.cols, src.rows, cv.CV_8UC3);
    contours = new cv.MatVector();
    hierarchy = new cv.Mat();
    color_scalar = new cv.Scalar(0, 255, 0);
    cv.findContours(thresholded, contours, hierarchy, 3, 2, [0, 0]);
    // for (var i = 0; i < contours.size(); i++) {
    //   cv.drawContours(thresholded, contours, i, color, 1, cv.LINE_8, hierarchy, 3, [0,0]);
    // }
    // cv.drawContours(thresholded, contours, -1, color_scalar, 1, cv.LINE_8, hierarchy, 3, [0,0]);
  }
  // }
  

  // image(capture, 0, 0, w, h);

  push();
  translate(-width/2, -height/2);
  if (contours && !showThresholded) {
    
    // noStroke();
    // console.log(contours.size());
    for (var i = 0; i < contours.size(); i++) {

        // fill(0);
        strokeWeight(5);
        stroke(0, 0, 0);
        var contour = contours.get(i);
        var vertex_dict = [];
        beginShape();
        var k = 0;
        for (var j = 0; j < contour.total(); j+=1) {
            var x = contour.get_int_at(k++);
            var y = contour.get_int_at(k++);
            vertex_dict[j] = [x,y];
        }

        let shuffled_array = shuffle(vertex_dict);
        for (var v = 0; v < shuffled_array.length; v++) {
          vertex(shuffled_array[v][0], shuffled_array[v][1]);
        }
        

        endShape(CLOSE);

        // stroke(100, 200, 200);
        // beginShape();
        // var k = 0;
        // for (var j = 0; j < contour.total(); j+=2) {
        //     randomSeed(j);
        //     stroke(j, 200, 200);
        //     var x = contour.get_int_at(k+=4);
        //     var y = contour.get_int_at(k+=4);
        //     vertex(x, y);
        //     // console.log('test');
        // }
        endShape(CLOSE);

        // noFill();
        stroke(255, 255, 255)
        // var box = cv.boundingRect(contour);
        // rect(box.x, box.y, box.width, box.height);

        // these aren't working right now:
        // https://github.com/ucisysarch/opencvjs/issues/30
//            var minAreaRect = cv.minAreaRect(contour);
//            var minAreaEllipse = cv.ellipse1(contour);
//            var fitEllipse = cv.fitEllipse(contour);
      }
    }
    pop();

    contour_img = get(0, 0, w, h);
    // console.log(contour_img.get(5, 100));
    // image(face_img, w/2, h/2, w, h);


  // let capture = cam.get();
  
//   capture.loadPixels();

//   // face_img = cam.get(0, 0, cam.width, cam.height);
  
//   let threshold = map(mouseX, 0, width, 0, 1);
  
//   for (let x = 0; x < capture.width; x++) {
//     for (let y = 0; y < capture.height; y++) {
//       let i = (x + y * capture.width) * 4;
//       let r = pixels[i+0];
//       let g = pixels[i+1];
//       let b = pixels[i+2];
//       let a = pixels[i+3];
      
//       let pixelColor;
//       // console.log(g);
//       if ((g / 255) > 0.5) {
//         pixelColor = 255;
//       } else {

//         pixelColor = 0;
//       }
      
//       pixels[i+0] = pixelColor;
//       pixels[i+1] = pixelColor;
//       pixels[i+2] = pixelColor;
//     }
//   }
//   capture.updatePixels();
  
  // face_img = capture.get(0, 0, capture.width, capture.height);

  
  
  // shader(theShader);
  
  // theShader.setUniform("u_resolution", [width, height]);
  // theShader.setUniform("u_time", millis() / 1000.0);
  // theShader.setUniform("u_mouse", [mouseX, map(mouseY, 0, height, height, 0)]);
  // theShader.setUniform("rockImg", rock_img);
  // theShader.setUniform("lineImg", line_img);
  // theShader.setUniform("faceImg", face_img);
  // theShader.setUniform("contourImg", contour_img);
  // theShader.setUniform('camera', capture);

  // // rect gives us some geometry on the screen
  // fill(255,0,0);
  // rect(0,0,width, height);
  
}

function windowResized(){
  resizeCanvas(windowWidth, windowHeight);
}