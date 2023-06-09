echo "list images"
docker images
echo "clear images"
docker rmi www-nuxt www-api mongo
echo "images cleared"
docker images
echo "images checked"
echo "lsit volume"
docker volume ls
echo "clear volumes"
docker volume rm www_api_main_container www_api_nodeModules_container www_mongodb_config_container www_mongodb_data_container www_nuxt_main_container www_nuxt_nodeModules_container
echo "volumes cleared"
docker volume ls
echo "volume check"
