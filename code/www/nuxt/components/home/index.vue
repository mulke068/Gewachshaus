<script lang="ts" setup>
import { objectExpression } from '@babel/types';
import THREE, { AmbientLight, GridHelper, PerspectiveCamera, PointLight, Scene, TextureLoader, Vector3, WebGLRenderer } from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { Ref } from 'vue';

let renderer: WebGLRenderer;
const container: Ref<HTMLCanvasElement | null> = ref(null);
let controls: OrbitControls;

const aspectRatio = computed(() => window.innerWidth / window.innerHeight);

const scene = new Scene();

const camera = new PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 100);
camera.position.set(0, 0, 15);
scene.add(camera);

const ambientLight = new AmbientLight( 0xcccccc, 0.4 );
scene.add( ambientLight );

const pointLight = new PointLight( 0xffffff, 0.8 );
camera.add( pointLight );
scene.add( camera );

const gridHelper = new GridHelper(50, 50);
gridHelper.position.set(0, 0, 0);
scene.add(gridHelper);

//const spaceTexture = new TextureLoader().load('_nuxt/assets/img/space.webp');
const spaceTexture = new TextureLoader().load('@assets/img/space.webp');
scene.background = spaceTexture;


import { MTLLoader } from 'three/examples/jsm/loaders/MTLLoader';
import { OBJLoader } from 'three/examples/jsm/loaders/OBJLoader';

const objMateial = new MTLLoader();
const objLoader = new OBJLoader();

objMateial.load('/3dObjects/test.mtl',
    (materials) => {
        materials.preload();
        objLoader.setMaterials(materials);
        objLoader.load('/3dObjects/test.obj',
            (object) => {
                //object.position.set(-43,39,0);
                object.position.set(0,0,0);
                object.scale.set(0.01, 0.01, 0.01);
                scene.add(object);
                // Setup renderer
                setRenderer();
                setSize();
            },
            (xhr) => {
                let count = Math.round(xhr.loaded / xhr.total * 100);
                console.log(String(count)+ '% 3dObject ');
            },
            (error) => {
                console.warn('An error happened loading 3DObject \n'+ error);
            }
        )
    }
);

/*
import { FBXLoader } from 'three/examples/jsm/loaders/FBXLoader';

const fbxLoader = new FBXLoader();

fbxLoader.load('/3dObjects/test.fbx',
    (object) => {
        object.position.set(0,0,0);
        object.scale.set(0.01, 0.01, 0.01);
        scene.add(object);
        // Setup renderer
        setRenderer();
        setSize();
    },
    (xhr) => {
        let count = Math.round(xhr.loaded / xhr.total * 100);
        console.log(String(count)+ '% 3dObject ');
    },
    (error) => {
        console.warn('An error happened loading 3DObject \n'+ error);
    }
)
*/
/*
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader';
import { DRACOLoader } from 'three/examples/jsm/loaders/DRACOLoader'

// Note that since Three release 148, you will find the Draco libraries in the `.\node_modules\three\examples\jsm\libs\draco\` folder.
const dracoLoader = new DRACOLoader()
dracoLoader.setDecoderPath('../.node_modules/three/examples/jsm/libs/draco/');

const loader = new GLTFLoader()
loader.setDRACOLoader(dracoLoader)
loader.load(
    '3dObjects/test.glb',
    function (gltf) {
        gltf.scene.traverse(function (child) {
            if ((child as THREE.Mesh).isMesh) {
                const m = child as THREE.Mesh
                m.receiveShadow = true
                m.castShadow = true
            }
            if ((child as THREE.Light).isLight) {
                const l = child as THREE.Light
                l.castShadow = true
                l.shadow.bias = -0.003
                l.shadow.mapSize.width = 2048
                l.shadow.mapSize.height = 2048
            }
        })
        scene.add(gltf.scene)
    },
    (xhr) => {
        console.log((xhr.loaded / xhr.total) * 100 + '% loaded')
    },
    (error) => {
        console.log(error)
    }
)
*/
function animate() {
    requestAnimationFrame(animate);
    controls.update();
    renderer.render(scene, camera);
}

window.onresize = () => {
    setSize();
} 

function setSize() {
    camera.aspect = aspectRatio.value;
    camera.updateProjectionMatrix();
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);
}

function setRenderer() {
    if (container.value) {
        renderer = new WebGLRenderer({
            canvas: container.value,
        });
        controls = new OrbitControls(camera, renderer.domElement);
        controls.enableDamping = true;
        animate();
    }
}
</script>

<template>
    <div>
        <div class="model">
            <canvas ref="container" id="container"></canvas>
        </div>
        <div class="content">
            <div class="container mx-auto">
                <h1 class="text-3xl ">
                    Home
                </h1>
                <p>
                    This is the home page
                </p>
                <p>
                    Work in Progress
                </p>
                <p>
                    Page View 3d Model from The Projeckt + Text Description
                </p>
            </div>
        </div>   
    </div>
</template>

<style scoped>
.model {
    position: fixed;
    width: 100vw;
    height: 100vh;
}
.content {
    position: static;
    width: 100vw;
    height: 80vh;
}
</style>

