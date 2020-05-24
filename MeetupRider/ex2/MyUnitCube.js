/**
 * MyUnitCube
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyUnitCube extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	initBuffers() {
		this.vertices = [
			0.5, 0.5,-0.5,	//0
			-0.5, 0.5, -0.5,	//1
            -0.5, -0.5, -0.5,  //2
            0.5, -0.5, -0.5,   //3
            0.5, 0.5, 0.5,	//4
			-0.5, 0.5, 0.5,	//5
            -0.5, -0.5, 0.5,  //6
            0.5, -0.5, 0.5,   //7
		];

		//Counter-clockwise reference of vertices
		this.indices = [
            0, 1, 2,
            0,2,1,
            0,3,2,
            0,2,3, //BAIXO

            1,2,5,
            1,5,2,
            2,6,5,
            2,5,6,//DIREITA

            0,1,4,
            0,4,1,
            1,5,4,
            1,4,5,//FRENTE

            0,3,7,
            0,7,3,
            0,7,4,
            0,4,7,//ESQUERDA 

            3,2,6,
            3,6,2,
            3,6,7,
            3,7,6,//TRÁS

            7,4,5,
            7,5,4,
            7,6,5,
            7,5,6//CIMA

		];

		//The defined indices (and corresponding vertices)
		//will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}