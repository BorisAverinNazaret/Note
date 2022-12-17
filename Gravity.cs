using System.Collections;
using System.Collections.Generic;
using UnityEngine;
/// <summary>
/// �������� ������ �� �������� �����
/// ���������� ������ � Unity 3D [Tutorial] (����� 1/2) - ��� � KSP
/// </summary>
public class Gravity : MonoBehaviour
{

    private HashSet<Rigidbody> affectedBodies = new HashSet<Rigidbody>();
    private Rigidbody componentRigidbody;
 

    void Start()
    {
        componentRigidbody = GetComponent<Rigidbody>();
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.attachedRigidbody != null)
            affectedBodies.Add(other.attachedRigidbody);
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.attachedRigidbody != null)
            affectedBodies.Remove(other.attachedRigidbody);
    }

    // Update is called once per frame
    void Update()
    {
        foreach (Rigidbody body in affectedBodies)
        {
            Vector3 directionToPlanet = (transform.position - body.position).normalized;

            float distance = (transform.position-body.position).magnitude;
            float strength = body.mass * componentRigidbody.mass / distance;

            body.AddForce(directionToPlanet * strength);
        }
        
    }
}
