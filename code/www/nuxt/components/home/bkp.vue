
<script lang="ts" setup>
import { AmbientLight, BoxGeometry, Color, GridHelper, Mesh, MeshBasicMaterial, PerspectiveCamera, PointLight, Scene, TextureLoader, WebGLRenderer } from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { OBJLoader } from 'three/examples/jsm/loaders/OBJLoader';
import { Ref } from 'vue';

let renderer: WebGLRenderer;
const html_scene: Ref<HTMLCanvasElement | null> = ref(null);
let controls: OrbitControls;

const aspectRatio = computed(() => window.innerWidth / window.innerHeight);

const scene = new Scene();

const camera = new PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.set(0, 0, 30);
scene.add(camera);

const ambientLight = new AmbientLight( 0xcccccc, 0.4 );
scene.add( ambientLight );

const pointLight = new PointLight( 0xffffff, 0.8 );
camera.add( pointLight );
scene.add( camera );

const gridHelper = new GridHelper(100, 100);
scene.add(gridHelper);

//const spaceTexture = new TextureLoader().load('_nuxt/assets/img/space.webp');
const spaceTexture = new TextureLoader().load('../../assets/img/space.webp');
scene.background = spaceTexture;

// Copilot off
const objLoader = new OBJLoader();
objLoader.load('/3dObjects/OBJ_PCB_Gewachshaus.obj', 
    (object) => {
        object.position.set(0, 0, 0);
        object.scale.set(0.01, 0.01, 0.01);
        scene.add(object);
    },
    (xhr) => {
        console.log((xhr.loaded / xhr.total * 100) + '% loaded');
    },
    (error) => {
        console.log('An error happened'+ error);
    }
)

function animate() {
    requestAnimationFrame(animate);
    controls.update();
    renderer.render(scene, camera);
}

function updateOrientation() {
    camera.aspect = aspectRatio.value;
    camera.updateProjectionMatrix();
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);
}

function setRenderer() {
    if (html_scene.value) {
        renderer = new WebGLRenderer({
            canvas: html_scene.value,
        });
        updateOrientation();
        controls = new OrbitControls(camera, renderer.domElement);
        controls.enableDamping = true;
        animate();
    }
}

watch(aspectRatio, () => {
    updateOrientation();
})

onMounted(() => {
    setRenderer();
})
</script>

<template>
    <div>
        <div class="scene">
            <canvas ref="html_scene" />
        </div>
        <div class="content">
        </div>
    </div>
</template>

<style scoped>
.scene {
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