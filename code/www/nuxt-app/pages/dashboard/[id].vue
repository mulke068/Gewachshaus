<template>
  <div>
    <div>
        {{ id }}
    </div>
    <p>Lorem ipsum dolor sit, amet consectetur adipisicing elit. Quod ex sapiente voluptatibus velit recusandae dolorem odio expedita ipsam adipisci at.</p>
  </div>
</template>

<script>
    const { id } = useRoute().params

    definePageMeta({
        layout: 'default',
    })
</script>
    
<style>

</style>