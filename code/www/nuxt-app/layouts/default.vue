import { NuxtLink } from '../.nuxt/components';

<template>
    <div>
        <header class="shadow-sm bg-minsk-900 h-28 w-screen">
            <nav class="container mx-auto p-4 flex justify-between">
                <div class="h-auto">
                    <NuxtLink href="/"><img src="../assets/img/logo_1024x1024.png" alt="logo" class="object-fill w-20 h-20"></NuxtLink>
                </div>
                <div class=" text-white-50 text-xl py-7">
                    <ul class="flex space-x-3 ">
                        <li><NuxtLink to="/">Home</NuxtLink></li>
                        <li><NuxtLink to="/dashboard">Dashboard</NuxtLink></li>
                    </ul>
                </div>
            </nav>
        </header>

        <!-- Output -->
        <article class=" shadow-md shadow-white-400 m-2">
            <div class="container mx-auto p-4">
                <slot />
            </div>
        </article>
    </div>
</template>

<script>
</script>

<style>
    .router-link-exact-active{
        color: #ff830d;
    }
</style>