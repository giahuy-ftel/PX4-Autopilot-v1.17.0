# Custom Gazebo Sim Maps

This folder is for project-local Gazebo Sim worlds and model assets that should
be tracked in this PX4-Autopilot fork without modifying the
`Tools/simulation/gz` submodule.

## Layout

Add custom worlds and assets like this:

```text
Tools/simulation/gz_custom/
  worlds/
    <world_name>.sdf
  models/
    <asset_model_name>/
      model.config
      model.sdf
      meshes, textures, materials, or other assets
```

The world file can reference local assets with `model://` URIs:

```xml
<uri>model://<asset_model_name>/mesh.obj</uri>
```

## Run

Use the world file name without `.sdf`:

```sh
PX4_GZ_WORLD=<world_name> make px4_sitl gz_x500
```

PX4 will use `Tools/simulation/gz_custom/worlds` when the requested world exists
there. Built-in worlds and models still come from `Tools/simulation/gz`.

## Validate

From the PX4 root:

```sh
export GZ_SIM_RESOURCE_PATH="$PWD/Tools/simulation/gz_custom/models:$PWD/Tools/simulation/gz_custom/worlds:$PWD/Tools/simulation/gz/models:$PWD/Tools/simulation/gz/worlds${GZ_SIM_RESOURCE_PATH:+:$GZ_SIM_RESOURCE_PATH}"
gz sim -s -r --iterations 1 Tools/simulation/gz_custom/worlds/<world_name>.sdf
```
