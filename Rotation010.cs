// using System.Collections;
// using System.Collections.Generic;
 using UnityEngine;
// using System;



public class Rotation010 : MonoBehaviour
{
    public float kofRot = 1f;
    void FixedUpdate()
    {
        // Debug.Log(this.transform.parent.position.z);            this.transform.up  this.transform.parent.localScale.y/1000
        // this.transform.Rotate d(this.transform.parent.position, this.transform.up, this.transform.localScale.y/1000  * -1 * Time.deltaTime);
        this.transform.RotateAround(this.transform.parent.position, this.transform.up, this.transform.parent.localScale.y/1000 * -1 * Time.deltaTime);
    }
}
//        transform.RotateAround(CentreOrbit.transform.position, AxisRotate, AngularVelocity * Time.deltaTime);
//        transform.RotateAround(Vector3.zero, new Vector3(45,45,0).normalized, AngularVelocity * Time.deltaTime);


/*    Три способа вращения/переворота
 * 
 * // Transform.rotation example.

// Rotate a GameObject using a Quaternion.
// Tilt the cube using the arrow keys. When the arrow keys are released
// the cube will be rotated back to the center using Slerp.

public class ExampleScript : MonoBehaviour
{
    float smooth = 5.0f;
    float tiltAngle = 60.0f;

    void Update()
    {
        // Smoothly tilts a transform towards a target rotation.
        float tiltAroundZ = Input.GetAxis("Horizontal") * tiltAngle;
        float tiltAroundX = Input.GetAxis("Vertical") * tiltAngle;

        // Rotate the cube by converting the angles into a quaternion.
        Quaternion target = Quaternion.Euler(tiltAroundX, 0, tiltAroundZ);

        // Dampen towards the target rotation
        transform.rotation = Quaternion.Slerp(transform.rotation, target,  Time.deltaTime * smooth);
    }
}

*/