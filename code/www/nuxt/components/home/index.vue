
<script lang="ts" setup>
    import {  GridHelper, PerspectiveCamera, Scene, TextureLoader, WebGLRenderer } from 'three';
    import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
    import { Ref } from 'vue';

    let renderer: WebGLRenderer;
    const html_scene: Ref<HTMLCanvasElement | null> = ref(null);

    const aspectRatio = computed(() => window.innerWidth / window.innerHeight);
    
    const scene = new Scene();

    const camera = new PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.set(0 , 0 , 30);
    scene.add(camera);

    const gridHelper = new GridHelper(100,100);
    scene.add(gridHelper);

    const spaceTexture = new TextureLoader().load('../../assets/img/space.jpg');
    scene.background = spaceTexture;

    function animate() {
        requestAnimationFrame(animate);
        renderer.render(scene, camera);
    }

    function updateCamera() {
        camera.aspect = aspectRatio.value;
        camera.updateProjectionMatrix();
    }

    function updateRenderer() { 
        //renderer.setPixelRatio(window.devicePixelRatio);
        renderer.setSize(window.innerWidth, window.innerHeight);
        renderer.render(scene, camera);
    }
    
    function setRenderer() {
        if (html_scene.value) {
            renderer = new WebGLRenderer( {
                canvas: html_scene.value,
            });
            updateRenderer()
            const controls = new OrbitControls(camera, renderer.domElement);
            animate();
        }
    }


    watch(aspectRatio, () => {
        updateCamera()
        updateRenderer();
    })

    onMounted(() => {
        setRenderer();
    })
</script>

<template>
    <div class="container">
        <canvas ref="html_scene" />
        <main class="content">
            <h1 class="title">
                Home
            </h1>
            <p class="description">
                This is the home page
            </p>
            <p>
                Work in Progress
            </p>
            <p>
                Page View 3d Model from The Projeckt + Text Description
            </p>
        </main>
    </div>
</template>

<style scoped>
.container {
    position: absolute;
}
canvas {
    width: 50wv;
    height: 50vh;
    position: fixed;
    top: 0;
    left: 0;
}
.content {
    position: absolute;
    top: 0;
    left: 0;
}
</style>