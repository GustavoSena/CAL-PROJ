/**
 * MyTangram
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTangram extends CGFobject {
	constructor(scene) {
        super(scene);
        this.smalltriangle1= new MyTriangleSmall(scene);
        this.smalltriangle2= new MyTriangleSmall(scene);
        this.bigtriangle1= new MyTriangleBig(scene);
        this.bigtriangle2= new MyTriangleBig(scene);
        this.diamond = new MyDiamond(scene);
        this.triangle = new MyTriangle(scene);
        this.parallelogram = new MyParallelogram(scene);
        
		
		
	}
	
    display(){
        this.scene.pushMatrix();
        var t1=[1,0, 0,0,
               0,1,0,0,
               0,0,1,0,
               0,Math.sqrt(8)+1,0,1
        ];
        this.scene.multMatrix(t1);
        this.diamond.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.translate(Math.sqrt(2),Math.sqrt(2),0);
        this.scene.rotate((Math.PI/4), 0, 0, 1) ;
        this.bigtriangle1.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.translate(-Math.sqrt(2),Math.sqrt(2),0);
        this.scene.rotate(Math.PI+Math.PI/4, 0, 0, 1) ;
        this.bigtriangle2.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.scale(-1,1,1);
        this.scene.rotate(-Math.PI/4, 0, 0, 1) ;
        this.parallelogram.display();
        this.scene.popMatrix();
        
        this.scene.pushMatrix();
        this.scene.translate(Math.sqrt(2)/2,-Math.sqrt(2)/2,0);
        this.scene.rotate(-Math.PI/2-Math.PI/4, 0, 0, 1) ;
        this.triangle.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.translate(3/2*Math.sqrt(2),-Math.sqrt(2)/2,0);
        this.scene.scale(1,-1,1);
        this.smalltriangle1.display();
        this.scene.popMatrix();

        this.scene.pushMatrix();
        this.scene.translate(-2.91,-1.5,0);
        this.scene.rotate(Math.PI/4, 0, 0, 1) ;
        this.smalltriangle2.display();
        this.scene.popMatrix();
    }
}
