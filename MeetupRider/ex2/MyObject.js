/**
 * MyObject
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyObject extends CGFobject {
	constructor(scene) {
        super(scene);
        this.tangram  = new MyTangram(scene);
        this.cube=new MyUnitCube(scene);
		
		
	}
	
    display(){

        this.scene.pushMatrix();
        this.tangram.display();
        this.scene.translate(0,0,-0.5);
        this.cube.display();
        this.scene.popMatrix();

    }
}
